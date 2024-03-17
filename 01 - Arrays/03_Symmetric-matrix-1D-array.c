#include<stdio.h>

void symmetric(int a[], int n) {
    int flag = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(a[i*n+j] != a[j*n+i]) {
                flag=1;
                break;
            }
        }
    }
    if(flag==0) {
        printf("\nSymmetric");
    } else {
        printf("\nNot Symmetric");
    }
}

int main() {
    int n, a[50];
    printf("\nEnter size: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0;j<n;j++) {
            printf("\nEnter elements: ");
            scanf("%d", &a[i*n+j]);
        }
    }
    printf("\nGiven matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%4d", a[i*n+j]);
        }
        printf("\n");
    }
    symmetric(a,n);
}