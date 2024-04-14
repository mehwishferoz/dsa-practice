#include<stdio.h>

void toh(int n, char a, char b, char c)
{
    if(n==0)
    return;
    toh(n-1,a,c,b);
    printf("%d %c -> %c\n", n, a, b);
    toh(n-1,c,b,a);
}

int main(){
    int n=3;
    char a='a', b='b', c='c';
    toh(n, a, b, c);
    return 0;
}