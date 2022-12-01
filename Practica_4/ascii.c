#include <stdio.h>

int main(void){
    register int i;

    for (i = 0; i < 256; i++)
        printf("%c:%i\n",i,i);

    return 0;
}