#include<stdio.h>

void main(){
    char a = 'A';
    char b = 'B';
    printf("%p\n", &a);
    printf("%p\n", &a+1);
    printf("%p\n", &b);
    printf("%p\n", &b+1);
}
