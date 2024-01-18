#include<stdio.h>
int LS(int[], int, int, int);

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
    int p = LS(a,0,n-1,v);
    if(p == -1) {
        printf("\nElement not found");
    } else {
        printf("\nElement found at position: %d", p);
    }
    return 0;
}

int LS(int a[10], int i, int j, int v) {
    if(i<=j) {
        if(a[i]==v) {
            return (i+1);
        } else {
            LS(a,i+1,j,v);
        }
    } else {
        return -1;
    }
}