#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int GROWING_DELTA = 10;
static int SHRINKING_DELTA = 20;
static float GROWING_FACTOR = 2.5;
static float SHRINKING_FACTOR = 3.0;

typedef int TInfo;

struct SDArray {
    TInfo* item;
    int capacity;
    int size;
};
typedef struct SDArray DArray;

DArray darray_create(int initial_size) {
    DArray a;
    a.item = (TInfo*) malloc(sizeof(TInfo) * initial_size);
    assert(initial_size==0 || a.item!=NULL);
    a.capacity = initial_size;
    a.size = initial_size;
    return a;
}

DArray darray_create_capac(int initial_size, int initial_capacity) {
    assert(initial_capacity >= initial_size);
    DArray a;
    a.item = (TInfo*) malloc(sizeof(TInfo) * initial_capacity);
    assert(initial_size==0 || a.item!=NULL);
    a.capacity = initial_capacity;
    a.size = initial_size;
    return a;
}

void darray_set(DArray* da, int pos, TInfo value) {
    (da->item)[pos] = value;
}

TInfo darray_get(DArray* da, int pos) {
    return (da->item)[pos];
}

void darray_print(DArray* da) {
    printf("[%d/%d]{", da->size, da->capacity);
    if(da->size>0){
        int i = 0;
        for(; i < da->size-1; i++) {
            printf("%d, ", da->item[i]);
        }
        printf("%d", da->item[i]);
    }
    printf("}");
}

void darray_destroy(DArray* da) {
    free(da->item);
    da->item = NULL;
    da->capacity = 0;
    da->size = 0;
}

void darray_resize_linear(DArray* da, int new_size) {
    if(new_size < 0) return; 
    printf("[LINEAR] Resize darray to new_size=%d. ", new_size);
    if(new_size > da->capacity || (da->capacity - new_size) > SHRINKING_DELTA) {
        const int new_capacity = new_size + GROWING_DELTA;
        printf("Setting capacity to %d.", new_capacity);
        da->item = (TInfo*) realloc(da->item, sizeof(TInfo) * new_capacity);
        da->capacity = new_capacity;
    }
    puts("");
    da->size = new_size;
}

void darray_resize_geometric(DArray* da, int new_size) {
    if(new_size < 0) return; 
    printf("[GEOMETRIC] Resize darray to new_size=%d. ", new_size);
    if(new_size > da->capacity || (da->capacity / new_size) > SHRINKING_FACTOR) {
        const int new_capacity = new_size * GROWING_FACTOR;
        printf("Setting capacity to %d.", new_capacity);
        da->item = (TInfo*) realloc(da->item, sizeof(TInfo) * new_capacity);
        da->capacity = new_capacity;
    }
    puts("");
    da->size = new_size;
}

static void (*f_resize)(DArray*,int) = &darray_resize_linear;
void darray_resize(DArray* da, int new_size) {
    f_resize(da, new_size);
}

void darray_append(DArray* da, TInfo value) {
    int curr_size = da->size; // NB: keep track of current size as resize will move it
    darray_resize(da, curr_size + 1);
    da->item[curr_size] = value;
}

void darray_remove_last(DArray* da) {
    darray_resize(da, da->size - 1);
}

void darray_expand(DArray* da, TInfo* arr, int sz) {
    int curr_size = da->size; // NB: keep track of current size as resize will move it
    darray_resize(da, curr_size + sz);
    for(int i=0; i<sz; i++) {
        darray_set(da, curr_size + i, arr[i]);
    }
}


/* Stack implementation */
struct stack
{
    DArray array;
};
typedef struct stack Stack;

Stack stack_create();
void  stack_destroy(Stack *s);
void  stack_push(Stack *s, int val);
TInfo stack_pop(Stack *s);
TInfo stack_top(Stack *s);
bool  isempty(Stack *s);
bool  isfull(Stack *s);
void  stack_print(Stack *s);

Stack stack_create(){
    Stack s;
    s.array = darray_create(0);
    return s;
}

void stack_destroy(Stack *s){
    darray_destroy(&s->array);
}

void stack_push(Stack *s, int val){
    darray_append(&s->array, val);
}

TInfo stack_pop(Stack *s){
    TInfo top = darray_get(&s->array, (s->array.size-1));
    darray_remove_last(&s->array);
    return top;
}

TInfo stack_top(Stack *s){
    TInfo top = darray_get(&s->array, (s->array.size-1));
    return top;
}

bool isempty(Stack *s){
    if (&s->array.size == 0) { return true; } else { return false; }
    
}

bool isfull(Stack *s){
    if (&s->array.size == 0) { return false; } else { return true; }
    
}

void stack_print(Stack *s) {
    printf("STACK: ");
    darray_print(&s->array);
}


/* Main */
int main() {
    Stack s = stack_create();
    stack_push(&s, 5);
    stack_push(&s, 6);
    stack_push(&s, 7);
    stack_print(&s);
    puts("");
    for(int i=0; i<3; i++) {
        printf("Pop: %d.\n", stack_pop(&s));
        stack_print(&s);
        puts("");
    }
    puts("");
    return 0;
}