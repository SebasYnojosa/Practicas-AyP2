#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    register int i;

    clock_t start = clock();

    for (i = 0; i < 500; i++){
        printf("%c",rand()%256);
    }

    for (i = 0; i < 30; i++){
        printf("%c",7);
        Sleep(500);
    }

    clock_t end = clock();

    printf("\n\nTiempo transcurrido: %i\n",(int)(end - start));

    return 0;
}