#include <stdio.h>
#include <stdlib.h>

typedef int TInfo;

struct list
{
    TInfo val;
    struct list *next;
};
typedef struct list list;

/* Function */
list *list_create(TInfo val, list *t);
void list_destroy(list *L);
void list_print(list *L);
int list_equal(list *L1, list *L2);
int list_lenght(list *L);
list *list_insert(list *L, int pos, TInfo val);


/* Implementation */
list *list_create(TInfo val, list *t){
    list *r = (list *) malloc(sizeof(list));
    if (r == NULL){ return NULL; }
    r->val = val;
    r->next = t;
    return r;
}

void list_destroy(list *L){
    if (L != NULL)
    {
        list_destroy(L->next);
        free(L);
    }   
}

void list_print(list *L){
    if (L == NULL)
    {
        printf("(END OF LIST)\n");
        printf("---\n");
        return;
    } 
    printf("(%d)\n", L->val);
    list_print(L->next);
}

int list_equal(list *L1, list *L2){
    if (L1 == NULL || L2 == NULL)
    {
        return L1 == NULL && L2 == NULL;
    }else{
        return L1->val == L2->val && list_equal(L1->next, L2->next);
    }
}

int list_lenght(list *L){
    if (L == NULL)
    {
        return 0;
    } else
    {
        return 1 + list_lenght(L->next);
    }
}

list *list_insert(list *L, int pos, TInfo val){
    if (pos == 0){ return list_create(val, L); }

    list *curr = L;
    int i = 0;

    for (; curr != NULL && i < pos - 1; i++, curr = curr->next); //Andiamo fino alla posizione desiderata

    if (i == pos - 1 && curr != NULL)
    {
        curr->next = list_create(val, curr->next); //Inserimento in posizione
    }
    return L;
}


/* Main */
int main(){

    list *L = list_create(15, list_create(5, list_create(2017, NULL))); //La lista sarà: [15, [5, [2017, NULL]]]
    list_print(L);
    
    L = list_insert(L, (list_lenght(L)), 11); //Mettiamo l'11 dopo il 2017
    list_print(L);

    list_destroy(L);

    return 0;
}
