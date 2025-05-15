#include <stdio.h>
#include <string.h>

int main(){

    char a[10];

    scanf("%s", a);
    printf("\nstring %s\n", a);
    printf("size of string %d\n", sizeof(a));
    printf("string lenght %d\n", strlen(a));
    a[strlen(a)] = '\0';
    printf("string lenght %d\n", strlen(a));
    printf("string %s\n", a);

    return 0;
}