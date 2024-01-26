#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void merge(int[],int,int);
void mergesort(int[],int,int,int);

int main() {
    int n,a[10];
    printf("\nEnter length of an array: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        printf("\nEnter elem: ");
        scanf("%d", &a[i]);
    }
    merge(a,0,n-1);

    printf("\nSorted Array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }
}

void merge(int a[10], int i, int j) {
    if(i<j) {
        int mid = (i+j)/2;
        merge(a, i, mid);
        merge(a, mid+1, j);
        mergesort(a,i,mid,j);
    }
}

void mergesort(int a[10], int i, int mid, int j) {
    int l=i;
    int p = mid+1;
    int k=i;
    int b[10];

    while(l<=mid && p<=j) {
        if(a[l]<a[p]) {
            b[k] = a[l];
            l++;
            k++;
        } 
        else {
            b[k] = a[p];
            p++;
            k++;
        }
    }
    while(l<=mid) {
        b[k] = a[l];
        l++;
        k++;
    }
    while(p<=j) {
        b[k] = a[p];
        p++;
        k++;
    }
    l=i;
    while(l<=j) {
        a[l] = b[l];
        l++;
    }
}