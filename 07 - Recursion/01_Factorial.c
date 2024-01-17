#include<stdio.h>
int fact(int);

int main() {
    int n;
    printf("\nEnter n: ");
    scanf("%d", &n);
    int p = fact(n);
    printf("\nFactorial: %d", p);
    return 0;
}

int fact(int n) {
    if(n==1 || n==0) {
        return 1;
    } else {
        return n*fact(n-1);
    }
}