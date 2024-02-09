#include <stdio.h>
#include <string.h>

int fact(int n);
double compute_perimeter(char* shape, double args[]);

int fact(int n) {
    int sol = 1;
    while (n > 0) {
        sol = sol * n;
        n--;
    }
    return sol;
}

double compute_perimeter(char* shape, double args[]) {
    if (strcmp(shape, "Quadrato") == 0) {
        double sol = args[0] * 4;
        return sol;
    }
    if (strcmp(shape, "Rettangolo") == 0) {
        double sol = (args[0] + args[1]) * 2;
        return sol;
    }
    if (strcmp(shape, "Cerchio") == 0) {
        double sol = args[0] * 3.14;
        return sol;
    }
    printf("Forma non riconosciuta\n");
    return 0.0;
}

int main(void) {
    printf("Fattoriale di 5: %d\n", fact(5));
    printf("\n#######\n");
    double lato = 2;
    double raggio = 2;
    double latiRett[] = {2, 4};
    
    printf("Perimetro di un quadrato con lato 2: %f\n", compute_perimeter("Quadrato", &lato));
    printf("Perimetro di un cerchio con raggio 2: %f\n", compute_perimeter("Cerchio", &raggio));
    printf("Perimetro di un rettangolo con lati 2 e 4: %f\n", compute_perimeter("Rettangolo", latiRett));
}
