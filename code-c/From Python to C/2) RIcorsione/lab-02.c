#include <stdbool.h>

//Definizioni
int sum_number(int a, int b);
int pow(int a, int n);
bool list_contains(int* lst, int elem, int len);
bool palindrome(char* string, int lenString);

//Implementazioni
int sum_number(int a, int b){
    if(a == b){
        return a;
    }
    return b + (sum_number(a, b-1));
}

int pow(int a, int n){
    if(n == 1){
        return a;
    }
    return a * (pow(a, n-1));
}

bool list_contains(int* lst, int elem, int len){
    if(len == 0){
        return false;
    }
    if(lst[0] == elem){
        return true;
    }

    int newArrayMinusOne[len - 1];
    for (int i = 1; i < len; i++)
    {
        newArrayMinusOne[i - 1] = lst[i];
    }

    return list_contains(newArrayMinusOne, elem, len - 1);
    
}

bool palindrome(char* string, int lenString){
    if(lenString == 1){ return true; }
    if(string[0] != string[lenString - 1]){ return false; } else{
        char trimString[lenString - 1];
        for (int i = 1; i < lenString - 1; i++)
        {
            trimString[i - 1] = string[i];
        }
        return palindrome(trimString, lenString - 2);
    }
}

//Test
int main(void){

    int array[] = {2,5,3,6};
    int numCont = 3;
    char string[] = "tenet";

    printf("Somma di tutti i numeri da 1 a 10: %d\n", sum_number(1,10));

    printf("2 alla 2: %d\n", pow(2,2));

    if(list_contains(array, numCont, 4)){
        printf("%d è contenuto\n", numCont);
    }else{
        printf("%d NON è contenuto\n", numCont);
    }

    if(palindrome(string, 5)){
        printf("%s è palindroma", string);
    }else{
        printf("%s NON è palindroma", string);
    }
}