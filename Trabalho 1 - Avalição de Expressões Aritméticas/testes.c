#include <stdio.h>
#include <ctype.h>

int main(){

    char a = ' ';

    do {
        scanf("%c", &a);
        if(isalpha(a))
            printf("%c is alpha\n", a);
        else if(isdigit(a))
            printf("%c is digit\n", a);
        else if(ispunct(a))
            printf("%c is punct\n", a);
    }while(a != '\'');

    return 0;

}