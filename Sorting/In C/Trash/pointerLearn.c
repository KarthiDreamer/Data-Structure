#include<stdio.h>

//no need for passing array as pointer to function
//https://www.programiz.com/c-programming/c-arrays-functions

int main(){
    int n=2;
    int *p=&n;
    printf("\nn=%d",n);
    printf("\n*p=%d",*p);
    printf("\n&=%x",&n);
    printf("\np=%x",p);
}