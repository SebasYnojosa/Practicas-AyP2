#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(){
    register int i;

    for (i = 0; i < 256; i++)
        printf("%c:%i\n",i,i);
    
    while (getch() != 0)
        printf("%c",7);

    while (getch() != 0)
        printf("%i\n",getch());

    printf("%c",84);
    printf("%c",117);
    printf("%c",32);
    printf("%c",80);
    printf("%c",117);
    printf("%c",116);
    printf("%c",97);
    printf("%c",32);
    printf("%c",77);
    printf("%c",97);
    printf("%c",100);
    printf("%c",114);
    printf("%c",101);
    printf("%c",10);

    return 0;
}