#include<stdio.h>

void quicksort(int[],int,int);
int partition(int[],int,int);

int main() {
    int n,a[10];
    printf("\nEnter length of an array: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        printf("\nEnter elem: ");
        scanf("%d", &a[i]);
    }
    quicksort(a,0,n);

    printf("\nSorted Array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }
}

void quicksort(int a[10], int l, int h) {
    int j;
    if(l<h) {
        j = partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}

int partition(int a[10], int i, int j) {
    int pivot = a[i];
    int p = i;
    int temp;
    while(i<j) {
        do {
            i++;
        }while(a[i]<=pivot);
        do {
            j--;
        }while(a[j]>pivot);
        if(i<j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[j];
    a[j] = a[p];
    a[p] = temp;
    
    return j;
}
