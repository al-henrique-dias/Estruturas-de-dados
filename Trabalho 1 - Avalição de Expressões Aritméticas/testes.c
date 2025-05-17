#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(){

    Pilha *a = NULL;
    empilhar('1', &a);
    empilhar('2', &a);
    printf("%d\n%d\n%d\n%c\n%d\n%c", a->elemento - '0', a->elemento+1 - '0', usar_topo(&a) - '0', a->elemento, usar_topo(&a) - '0', a->elemento);

    return 0;
}