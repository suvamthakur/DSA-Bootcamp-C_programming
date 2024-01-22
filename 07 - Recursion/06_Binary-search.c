#include<stdio.h>
int binarySearch(int[], int, int, int);

int main() {
    int a[10], n, v;
    printf("\nEnter length of array: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        printf("\nEnter elem: ");
        scanf("%d", &a[i]);
    }
    printf("\nEnter searching element: ");
    scanf("%d", &v);
    int p = binarySearch(a,0,n-1,v);
    if(p == -1) {
        printf("\nElement not found");
    } else {
        printf("\nElement found at position: %d", p);
    }
    return 0;
}

int binarySearch(int a[10], int i, int j, int v) {
    if(i<j) {
        int mid = (i+j)/2;
        if(a[mid] == v) {
            return mid+1;
        }
        else if(a[mid]>v) {
            binarySearch(a, 0, mid-1, v);
        } else {
            binarySearch(a, mid+1, j, v);
        }
    } else {
        return -1;
    }
}