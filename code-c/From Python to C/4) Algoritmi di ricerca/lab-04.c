#include <stdio.h>

//Definizioni
int linearSearch(int* array, int len, int elem);
int binarySearch(int* array, int from, int to, int elem);


//Implementazioni
int linearSearch(int* array, int len, int elem){
    for (int i = 0; i < len; i++)
    {
        if(array[i] == elem){ return i; }
    }
    return -1;
}

//Necessario un array ordinato
int binarySearch(int* array, int from, int to, int elem) {
    // In caso l'intervallo di ricerca è vuoto
    if (from > to) {
        return -1;
    }

    // Trovato l'elemento
    int pivot = (from + to) / 2;
    if (array[pivot] == elem) {
        return pivot;
    }

    // L'elemento potrebbe essere nel sottoinsieme DX
    if (array[pivot] < elem) {
        return binarySearch(array, pivot + 1, to, elem);
    }
    // L'elemento potrebbe essere nel sottoinsieme SX
    else {
        return binarySearch(array, from, pivot - 1, elem);
    }
}


//Test
int main(void){
    int len = 5;
    int array[] = {3, 5, 1, 7, 4};
    int arrayOrd[] = {1, 2, 3, 4, 5};
    int elemPresente = 1;
    int elemNonPresente = 9;

    printf("### Linear-Search ###\n");
    printf("L'elemento %d è presente nell'array in posizione: %d\n",elemPresente, linearSearch(array, len, elemPresente));
    printf("L'elemento %d non è presente, ritorno -1: %d\n",elemNonPresente, linearSearch(array, len, elemNonPresente));

    printf("### Binary-Search ###\n");
    printf("L'elemento %d è presente nell'array in posizione: %d\n",elemPresente, binarySearch(arrayOrd, 0, len - 1, elemPresente));
    printf("L'elemento %d non è presente, ritorno -1: %d\n",elemNonPresente, binarySearch(arrayOrd, 0, len - 1, elemNonPresente));
}