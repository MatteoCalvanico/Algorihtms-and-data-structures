#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TInfo;

//Possiamo farli senza array dinamici
struct SQueue
{
    TInfo *item;  //Rappresenta l'insieme di elementi
    int from;     //Rappresenta la testa (primo elemento)
    int size;     //Rappresenta il numero di valori presenti
    int capacity; //Rappresenta quanti valori possiamo tenere
};
typedef struct SQueue Queue;

//O con gli array dinamici
struct SDarray
{
    TInfo *item;
    int size;
    int capacity;
};
typedef struct SDarray Darray; //Array dinamico che ci serve per la coda

struct SDQueue
{
    Darray array;
    int from;     //Rappresenta la testa (primo elemento)
    int size;
};


/* Funzioni */
Queue  queue_create(int capacity);

void   queue_destroy(Queue* q);

void   queue_add(Queue *q, TInfo val);   //Enqueue (b = (b + 1)%capacity), dove b è il 'back' della coda calcolabile tramite f + n (front + numero di valori)

TInfo  queue_remove(Queue *q);           //Dequeue (f = (f + 1)%capacity), semplicemente andiamo a spostare di uno in avanti la testa

bool   queue_offer(Queue *q, TInfo val); //Add tolerating full

TInfo* queue__poll(Queue *q);            //Null if empty

TInfo  front(Queue *q);                  //Peek

TInfo* peek(Queue *q);                   //Null if empty

bool   queue_isempty(Queue *q);

bool   queue_isfull(Queue * q);


/* Implementazioni */
Queue queue_create(int capacity){
    Queue q;

    assert(capacity > 0);
    q.item = (TInfo*) malloc(sizeof(TInfo) * capacity);

    assert(q.item != NULL);
    q.capacity = capacity;
    q.size = 0;
    q.from = 0;

    return q;
}

void queue_destroy(Queue* q){
    free(q->item);
    q->item = NULL;
    q->capacity = 0;
    q->size = 0;
    q->from = 0;
}

void queue_add(Queue *q, TInfo val){
    int back;

    if (queue_isfull(q)) //Essendo circolare se la capacità e la size sono uguali sposto la testa uno più avanti andando poi a sovrascrivere quella vecchia
    {
        q->from = (q->from + 1) % q->capacity; 
    }
    
    back = (q->from + q->size) % q->capacity;
    (q->item)[back] = val;

    if (!queue_isfull(q)) //Aumentiamo il numero di elementi presenti solo se non è piena, altrimenti rimane uguale perchè abbiamo sostituito la vecchia testa con il nuovo elemento
    {
        q->size++;
    }
}

TInfo queue_remove(Queue *q){
    assert(q->size > 0);

    TInfo val = q->item[q->from];
    q->from = (q->from + 1) % q->capacity;
    q->size--;

    return val;
}

//Offer: tenta di aggiungere un elemento alla coda senza generare un errore se la coda è piena
bool queue_offer(Queue *q, TInfo val){
    if (q->size == q->capacity) {
        return false; // La coda è piena, non possiamo aggiungere
    }

    queue_add(q, val);
    return true;
}

//Poll: tenta di rimuovere e restituire l'elemento in testa alla coda
TInfo* queue_poll(Queue *q){
    if (q->size == 0) {
        return NULL; // La coda è vuota
    }

    return &q->item[q->from];
}

TInfo front(Queue *q){
    assert(q->size > 0);
    return q->item[q->from];
}

TInfo* peek(Queue *q){
    if (queue_isempty(q)) {
        return NULL;
    }

    return &q->item[q->from];
}

bool queue_isempty(Queue *q){
    return q->size == 0;
}

bool queue_isfull(Queue *q){
    return q->size == q->capacity;
}