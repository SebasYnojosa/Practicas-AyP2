/*
    Escriba rutinas de ordenamientos por intercambio (sort1), selección
    (sort2), inserción(sort3) y quicksort(qsort). Y utilizando cada unas de ellas
    ordenen la secuencia 20, 34, 11, 54, 33, 10, 15, 55, 99, 40. Realice un
    cuadro comparativo con el número de comparaciones e intercambios. 
*/

#include <stdio.h>

/* Contadores globales */
int comparaciones = 0;
int intercambios = 0;

/* Declaración de funciones */
void print(int array[], int size);              // Imprimir arreglo
void swap(int array[], int i, int j);           // Intercambio entre dos elementos
void sort1(int array[], int size);              // Intercambio
void sort2(int array[], int size);              // Selección
void sort3(int array[], int size);              // Inserción
void qsort(int array[], int begin, int end);    // Quicksort
int particion(int array[], int begin, int end); // Funcion para obtener el pivote en quicksort


int main(void){
    int arreglo1[] = {20,34,11,54,33,10,15,55,99,40};   // Arreglo para Quicksort
    int arreglo2[] = {20,34,11,54,33,10,15,55,99,40};   // Arreglo para Intercambio
    int arreglo3[] = {20,34,11,54,33,10,15,55,99,40};   // Arreglo para Selección
    int arreglo4[] = {20,34,11,54,33,10,15,55,99,40};   // Arreglo para Inserción
    int tam = sizeof(arreglo1)/sizeof(arreglo1[0]);

    /* Ordena el arreglo mediante Quicksort */
    print(arreglo1,tam);
    qsort(arreglo1,0,tam-1);
    printf("Arreglo ordenado por Quicksort\n");
    printf("Comparaciones:%d - Intercambios:%d\n",comparaciones,intercambios);
    print(arreglo1,tam);

    /* Ordena el arreglo mediante Intercambio */
    comparaciones = 0;
    intercambios = 0;
    sort1(arreglo2,tam);
    printf("\nArreglo ordenado por Intercambio\n");
    printf("Comparaciones:%d - Intercambios:%d\n",comparaciones,intercambios);
    print(arreglo2,tam);

    /* Ordena el arreglo mediante Selección */
    comparaciones = 0;
    intercambios = 0;
    sort2(arreglo3,tam);
    printf("\nArreglo ordenado por Seleccion\n");
    printf("Comparaciones:%d - Intercambios:%d\n",comparaciones,intercambios);
    print(arreglo3,tam);

    /* Ordena el arreglo mediante Inserción */
    comparaciones = 0;
    intercambios = 0;
    sort3(arreglo4,tam);
    printf("\nArreglo ordenado por insercion\n");
    printf("Comparaciones:%d - Intercambios:%d\n",comparaciones,intercambios);
    print(arreglo4,tam);



    return 0;
}

void print(int array[], int size){
    register int i;
    for (i = 0; i < size; i++)
        printf("%d ",array[i]);
    printf("\n\n");
}

void swap(int array[], int i, int j){
    int t;  // Auxiliar

    t = array[i];
    array[i] = array[j];
    array[j] = t;
}

int particion(int array[], int begin, int end){
    int i,j,pivot;

    pivot = array[end]; // usa de pivote al ultimo elemento del arreglo
    i = begin-1;
    
    for (j = begin; j <= end-1; j++){
        if (array[j] < pivot){
            i++;
            swap(array,i,j);
            intercambios++;
        }
        comparaciones++;
    }
    i++;
    swap(array,i,end);
    intercambios++;
    return i;
}

void qsort(int array[], int begin, int end){
    int pivot;

    if (begin < end){
        pivot = particion(array,begin,end); // obtiene el indice del pivote y lo pone en la posicion que debe estar
        qsort(array,begin,pivot-1);     // la parte izquierda al pivote
        qsort(array,pivot+1,end);       // la parte derecha al pivote
    } 
}

void sort1(int array[], int size){
    register int i,j;

    for (i = 0; i < size-1; i++){
        for (j = i+1; j < size; j++){
            if(array[i] > array[j]){
                swap(array,i,j);
                intercambios++;
            }
            comparaciones++;
        }
    }
}

void sort2(int array[], int size){
    register int min, i, j;

    for (i = 0; i < size-1; i++){
        min = i;
        for (j = i+1; j < size; j++){
            if (array[min] > array[j])
                min = j;
            comparaciones++;
        }
        if (i != min){
            swap(array,i,min);
            intercambios++;
        }
    }
}

void sort3(int array[], int size){
    int i,j,aux;

    for (i = 1; i < size; i++){
        aux = array[i];
        for (j = i; j > 0 && aux < array[j-1]; j--){
            array[j] = array[j-1];
            comparaciones++;
            intercambios++;
        }
        if (j > 0) // No cuenta el caso en que no se hace la comparacion en el for
            comparaciones++;
        array[j] = aux;
    }
}