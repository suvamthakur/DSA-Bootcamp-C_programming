#include<stdio.h>
int fibo(int);

int main() {
    int n;
    printf("\nEnter n: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int f = fibo(i);
        printf("%4d", f);
    }
    return 0;
}

int fibo(int n) {
    if(n==0) {
        return 0;
    }
    else if(n==1) {
        return 1;
    } else {
        return (fibo(n-1) + fibo(n-2));
    }
}