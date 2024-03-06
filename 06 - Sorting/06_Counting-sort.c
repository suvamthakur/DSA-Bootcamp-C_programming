#include<stdio.h>
#include<malloc.h>
void coutingsort(int a[], int n);

int main() {
    int n,a[20];
    printf("\nEnter length of array: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        printf("\nEnter elem: ");
        scanf("%d", &a[i]);
    }
    printf("\nGiven array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }
    coutingsort(a,n);
    printf("\nSorted array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }

    return 0;
}

void coutingsort(int a[], int n) {
    int max;
    max = maxNumber(a,n);

    int c[max];
    for(int i=0;i<=max;i++) {
        c[i] = 0;
    }
    freqSearch(a,c,n);
    findIndex(c,max);
    sort(a,c,n);
}

int maxNumber(int a[10], int n) {
    int max = a[0];
    for(int i=0;i<n;i++) {
        if(max < a[i]) {
            max = a[i];
        }
    }
    return max;
}
void freqSearch(int a[], int c[],int n) {
    for(int i=0;i<n;i++) {
        c[a[i]]++;
    }
}
void findIndex(int c[], int max) {
    for(int i=1;i<=max;i++) {
        c[i] = c[i] + c[i-1];
    }
}
void sort(int a[], int c[], int n) {
    int y[20];
    for(int i=n-1;i>=0;i--) {
        y[c[a[i]]-1] = a[i];
        c[a[i]]--;
    }
    for(int i=0;i<n;i++) {
        a[i] = y[i];
    }
}