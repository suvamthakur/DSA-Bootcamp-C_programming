#include<stdio.h>
void selectionsort(int[], int, int);

int main() {
    int n,a[10];
    printf("\nEnter length of an array: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        printf("\nEnter elem: ");
        scanf("%d", &a[i]);
    }
    selectionsort(a,0,n);

    printf("\nSorted Array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }
}

void selectionsort(int a[10], int i, int n) {
    int temp;
    if(i<n) {
        int p = i;
        for(int j=i+1;j<n;j++) {
            if(a[j]<a[p]) {
                p = j;
            }
        }
        temp = a[i];
        a[i] = a[p];
        a[p] = temp;
        selectionsort(a,i+1,n);
    }
}