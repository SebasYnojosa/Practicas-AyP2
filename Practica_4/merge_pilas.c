/*
    Programa para mezclar pilas
*/

#include <stdio.h>

#define MAX_PILAS 25

typedef struct{
    int elem[MAX_PILAS];
    int tope;
}pila_t;

void anula(pila_t *pilap){
    pilap->tope = -1;
}

int vacia(pila_t *pilap){
    return pilap->tope == -1;
}

int push(pila_t *pilap, int dato){
    if (pilap->tope == MAX_PILAS-1)
        return 0;

    pilap->elem[++pilap->tope] = dato;
    return 1;
}

int top(pila_t *pilap, int *dato){
    if (vacia(pilap)) return 0;

    *dato = pilap->elem[pilap->tope];
    return 1;
}

int pop(pila_t *pilap, int *dato){
    if (vacia(pilap)) return 0;

    *dato = pilap->elem[pilap->tope--];
    return 1;
}

int merge(pila_t *pilap1, pila_t *pilap2){
    if (vacia(pilap1) && vacia(pilap2)) return 0;


}

int main(void){
    pila_t nueva_pila1, nueva_pila2;
    int elementos1[] = {5,4,3};
    int tam1 = sizeof(elementos1)/sizeof(elementos1[0]);
    int elementos2[] = {10,8,7};
    int tam2 = sizeof(elementos2)/sizeof(elementos2[0]);

    register int i;
    int tope;

    printf("\t---Implementaci%cn de pila---\n\n",162);
    
    anula(&nueva_pila1);
    anula(&nueva_pila2);

    for (i = 0; i < tam1; i++)
        push(&nueva_pila1, elementos1[i]);

    if (!vacia(&nueva_pila1)){
        top(&nueva_pila1, &tope);
        printf("El elemento del tope de la pila 1 es %d\n",tope);
    } else 
        printf("La pila 1 no tiene elementos\n\n");

    while (pop(&nueva_pila1,&tope))
        printf("%d\n",tope);
    printf("\n");

    for (i = 0; i < tam2; i++)
        push(&nueva_pila2, elementos2[i]);

    if (!vacia(&nueva_pila2)){
        top(&nueva_pila2,&tope);
        printf("El elementos del tope de la pila 2 es %d\n",tope);
    } else 
        printf("La pila 2 no tiene elementos\n\n");

    while (pop(&nueva_pila2,&tope))
        printf("%d\n");
    printf("\n");
    


    
    


    return 0;
}