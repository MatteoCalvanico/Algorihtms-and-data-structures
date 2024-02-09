#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//Utility function
int min(int* a, int start, int len);
int* cut(int* a, int from, int to);


//Declarations
void selectionSort(int* a, int len);
void insertionSort(int* a, int len);
void bubbleSort(int* a, int len);
void mergeSort(int* a, int len);
int* merge(int* a, int* b, int* r, int lenA, int lenB);
void quickSort(int* a, int start, int to);
int partition(int* a, int start, int to, int len);


//Implementations
int min(int* a, int start, int len){  //Return index of min elem
    int indexMin = start;
    for (int i = start; i < len; i++)
    {
        if(a[i] < a[indexMin]){ indexMin = i; }
    }
    return indexMin;
}

int* cut(int* a, int start, int fin){ //Return the array we pass cut from 'start' to 'fin' 
    int* r = malloc((fin - start + 1) * sizeof(int));
    int j = 0;
    for (int i = start; i <= fin; i++)
    {
        r[j++] = a[i];
    }
    return r;
}

int partition(int* a, int start, int to, int len){ //Return the position of a pivot, after we split the array in two part, left part = elem < pivot, right part = elem > pivot
    int pivotIndex = start;
    int k = start + 1;  //Mi servirà per spostare il pivot nel punto giusto
    int temp;

    for (int i = start + 1; i < to; i++)
    {
        if (a[i] < a[pivotIndex])
        {
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
            k++;
        }
    }
    temp = a[pivotIndex];
    a[pivotIndex] = a[k - 1];
    a[k - 1] = temp;

    return k - 1;
}
//-------------------------------------------------------------------------------------------
void selectionSort(int* a, int len){
    for (int i = 0; i < len - 1; i++)
    {
        int minIndex = min(a, i, len);
        if(i != minIndex){
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
    
}

void insertionSort(int* a, int len){
    for (int i = 1; i < len; i++)
    {
        int valToSwap = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > valToSwap) //Spostiamo l'array a destra finchè non arriviamo nella posizione giusta
        {
            a[j + 1] = a[j]; //Spostiamo a destra il valore maggiore
            j -= 1;
        }
        a[j + 1] = valToSwap;
    }
    
}

void bubbleSort(int* a, int len){
    bool stillSwap = true;
    while (stillSwap)
    {
        stillSwap = false;
        for (int i = 1; i < len; i++)
        {
            if(a[i - 1] > a[i]){
                int temp = a[i - 1];
                a[i - 1] = a[i];
                a[i] = temp;

                stillSwap = true;
            }
        }
        
    }
    
}

void mergeSort(int* a, int len){
    if(len <= 1){ return; }

    int pivot = len/2;
    int* left = cut(a, 0, pivot - 1);
    int* right = cut(a, pivot, len - 1);

    int lenLeft = pivot;        //(sizeof(left)/sizeof(left[0]));
    int lenRight = len - pivot; //(sizeof(right)/sizeof(right[0]));

    int* final = malloc(len * sizeof(int));
    mergeSort(left, lenLeft);
    mergeSort(right, lenRight);
    merge(left, right, final, lenLeft, lenRight);

    for (int i = 0; i < len; i++)
    {
        a[i] = final[i];
    } 

    free(left);
    free(right);
    free(final);
}

int* merge(int* a, int* b, int* r, int lenA, int lenB){
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < lenA && j < lenB)
    {
        if (a[i] <= b[j])
        {
            r[k] = a[i++];
        }else
        {
            r[k] = b[j++];
        }
        k++;
    }
    while (i < lenA) {
        r[k++] = a[i++];
    }
    while (j < lenB) {
        r[k++] = b[j++];
    }
    return r;
}

void quickSort(int* a, int start, int to){
    if (start < to)
    {
        int len = (sizeof(a)/sizeof(a[0]));
        int indexPivot = partition(a, start, to, len);

        quickSort(a, start, indexPivot);
        quickSort(a, indexPivot + 1, to);
    }
}


//Main
int main(void){
    int a[] = {2,4,3,1};
    int len = 4; 


    selectionSort(a, len);
    printf("\nArray order by selection sort: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d", a[i]);
    }

    int b[] = {2,4,3,1};
    
    insertionSort(b, len);
    printf("\nArray order by insertion sort: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d", b[i]);
    }
    
    int c[] = {2,4,3,1};
    
    bubbleSort(c, len);
    printf("\nArray order by Bubble sort: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d", c[i]);
    }
        
    int d[] = {2,4,3,1,7};
    
    mergeSort(d, 5);
    printf("\nArray order by Merge sort: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", d[i]);
    }
        
    int e[] = {2,4,3,1,7};
    
    quickSort(e, 0, 5);
    printf("\nArray order by Quick sort: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", e[i]);
    }


    return 0;
}