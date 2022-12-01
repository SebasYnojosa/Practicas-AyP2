// Algoritmo de ordenamiento aleatorio (BogoSort)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Funcion para hacer un intercambio entre los elementos de las posiciones i y j de un arreglo */
void swap(int array[], int i, int j);
/* Funcion para barajear el arreglo */
void shuffle(int array[], int size);
/* Funcion para verificar si el arreglo esta ordenado */
void bogoSort(int array[], int size);
/* Funcion para imprimir un arreglo */
void printArray(int array[], int size);

int main(void){
    srand(time(NULL));
    int arreglo[] = {7,5,3,4,7,9,7,5,3,8,9,5,4,2,1};
    int lenght = sizeof(arreglo)/sizeof(arreglo[0]); // Longitud del arreglo
    
    printArray(arreglo,lenght);
    
    clock_t start = clock();

    bogoSort(arreglo,lenght);

    clock_t end = clock();

    printf("Arreglo Ordenado!!!!!\n");
    printArray(arreglo,lenght);
    printf("Tiempo: %d\n",(int)(end - start));
    printf("%c",7); // Alarma

    return EXIT_SUCCESS;
}

/* Funcion para hacer un intercambio entre los elementos de las posiciones i y j de un arreglo */
void swap(int array[], int i, int j){
    int aux;

    aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

/* Funcion para barajear el arreglo */
void shuffle(int array[], int size){
    register int i;

    for (i = 0; i < size; i++)
        swap(array,i,rand()%size);
}

/* Funcion para verificar si el arreglo esta ordenado */
void bogoSort(int array[], int size){
    register int i, f = 0;
    unsigned long long int shuf_cont, comp_cont;

    shuf_cont = comp_cont = 0; 

    while (f == 0){
        f = 1;
        for (i = 0; i < size-1 && f == 1; i++){ // Bucle que recorre el arreglo mientras f sea verdadera
            if (array[i+1] < array[i]) f = 0;
            comp_cont++;
        }

        if (f == 0){
            shuffle(array,size);
            shuf_cont++;
            //printArray(array,size);
        }
    }
    printf("\nDespu%cs de %d comparaciones\n",130,comp_cont);
    printf("y %d barajeos del arreglo\n",shuf_cont);
}

/* Funcion para imprimir un arreglo */
void printArray(int array[], int size){
    register int i; // Control del bucle

    for (i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}