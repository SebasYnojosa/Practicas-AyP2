// Algoritmo de ordenamiento shellsort

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

#define CANTIDAD 100

void print(int array[], int size){
    register int i;
    for (i = 0; i < size; i++)
        printf("%d ",array[i]);
    printf("\n");
}

void swap(int array[], int a, int b){
    int aux;

    aux = array[a];
    array[a] = array[b];
    array[b] = aux;
}

void rand_array(int array[], int size){
    register int i;

    for (i = 0; i < size; i++)
        array[i] = rand()%CANTIDAD;
}

int particion(int array[], int begin, int end){
    int i,j,pivot;

    pivot = array[end]; // usa de pivote al ultimo elemento del arreglo
    i = begin-1;
    
    for (j = begin; j <= end-1; j++){
        if (array[j] < pivot){
            i++;
            swap(array,i,j);
        }
    }
    i++;
    swap(array,i,end);
    return i;
}

void quicksort(int array[], int begin, int end){
    int pivot;

    if (begin <= end){
        pivot = particion(array,begin,end); // obtiene el indice del pivote y lo pone en la posicion que debe estar
        quicksort(array,begin,pivot-1);     // la parte izquierda al pivote
        quicksort(array,pivot+1,end);       // la parte derecha al pivote
    } 
}

void bubblesort(int array[], int size){
    register int i,j;

    for (i = 0; i < size-1; i++){
        for (j = 0; j < size-i-1; j++){
            if (array[j] > array[j+1]){
                swap(array,j,j+1);
            }
        }
    }
}

void insertsort(int array[], int size){
    int i,j,aux;

    for (i = 1; i < size; i++){
        aux = array[i];
        for (j = i; j > 0 && aux < array[j-1]; j--)
            array[j] = array[j-1];
        array[j] = aux;
    }
}

void selectionsort(int array[], int size){
    register int min, i, j;

    for (i = 0; i < size-1; i++){
        min = i;
        for (j = i+1; j < size; j++){
            if (array[min] > array[j])
                min = j;
        }
        if (i != min)
            swap(array,i,min);
    }
}

void merge(int leftArray[], int rightArray[], int array[]){
    int size = sizeof(array)/sizeof(array[0]);

    int leftSize = size/2;
    int rightSize = size - leftSize;

    int i = 0; // Arreglo original
    int l = 0; // Arreglo izquierdo
    int r = 0; // Arreglo derecho

    // Condiciones de mezcla

    while (l < leftSize && r < rightSize){
        if (leftArray[l] < rightArray[r]){
            array[i] = leftArray[l];
            i++;
            l++;
        }
        else {
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }
    while (l < leftSize){
        array[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < rightSize){
        array[i] = rightArray[r];
        i++;
        r++;
    }
}

void mergesort(int array[]){
    int size = sizeof(array)/sizeof(array[0]);

    if (size <= 1) return; // caso base

    int middle = size/2;
    int leftArray[middle];
    int rightArray[size - middle];

    int i = 0; // Arreglo izquierdo
    int j = 0; // Arreglo derecho

    for (; i < size; i++){
        if (i < middle){
            leftArray[i] = array[i];
        }
        else {
            rightArray[j] = array[i];
            j++;
        }
    }
    mergesort(leftArray);
    mergesort(rightArray);
    merge(leftArray,rightArray,array);
}

int main(void){
    srand(time(NULL));
    int arreglo1[CANTIDAD];
    int tam1 = CANTIDAD;

    printf("%d\n", sizeof(arreglo1)/sizeof(arreglo1[0]));

    rand_array(arreglo1,tam1);

    clock_t start_quick = clock();

    quicksort(arreglo1,0,tam1-1);

    clock_t end_quick = clock();

    printf("Arreglo ordenado por quicksort\n");
    print(arreglo1,tam1);
    printf("\nTiempo de ejecucion: %i\n",(int)(end_quick-start_quick));

    getch();

    int arreglo2[CANTIDAD];
    int tam2 = CANTIDAD;

    rand_array(arreglo2,tam2);

    clock_t start_bubble = clock();

    bubblesort(arreglo2,tam2);

    clock_t end_bubble = clock();

    printf("\n\nArreglo ordenado por burbuja\n");
    printf("Tiempo de ejecucion: %i\n",(int)(end_bubble-start_bubble));

    getch();

    int arreglo3[CANTIDAD];
    int tam3 = CANTIDAD;

    rand_array(arreglo3,tam3);

    clock_t start_insert = clock();

    insertsort(arreglo3,tam3);

    clock_t end_insert = clock();

    printf("\n\nArreglo ordenado por insercion\n");
    printf("Tiempo de ejecucion: %i\n",(int)(end_insert-start_insert));

    int arreglo4[CANTIDAD];
    int tam4 = CANTIDAD;

    rand_array(arreglo4,tam4);

    clock_t start_selection = clock();

    selectionsort(arreglo4,tam4);

    clock_t end_selection = clock();

    printf("\n\nArreglo ordenado por seleccion\n");
    printf("Tiempo de ejecucion: %i\n",(int)(end_selection-start_selection));

    getch();

    int arreglo5[CANTIDAD];
    int tam5 = CANTIDAD;

    rand_array(arreglo5,tam5);

    clock_t start_merge = clock();

    mergesort(arreglo5);

    clock_t end_merge = clock();

    printf("\n\nArreglo ordenado por mezcla\n");
    print(arreglo5,tam5);
    printf("Tiempo de ejecucion: %i\n",(int)(end_merge-start_merge));

    return 0;
}