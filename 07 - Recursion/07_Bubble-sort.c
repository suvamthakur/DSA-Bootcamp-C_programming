#include<stdio.h>
void bubblesort(int[], int);

int main() {
    int n,a[10];
    printf("\nEnter length of an array: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        printf("\nEnter elem: ");
        scanf("%d", &a[i]);
    }

    bubblesort(a,n);

    printf("\nSorted Array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }
}

void bubblesort(int a[10], int n) {
    int temp;
    if(n>0) {
        for(int i=0;i<n;i++) {
            if(a[i]>a[i+1]) {
                temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
            }
        }
        bubblesort(a, n-1);
    }
}