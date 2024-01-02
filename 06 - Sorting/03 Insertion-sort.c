#include<stdio.h>
void insertionsort(int[],int);
int main()
{
    int a[10],n;
    printf("\nEnter length of array: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        printf("\nEnter array elem: ");
        scanf("%d", &a[i]);
    }
    printf("\nGiven array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }
    insertionsort(a,n);
    printf("\nSorted array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }
    return 0;
}

void insertionsort(int a[10], int n) {
    int loc,i,j;
    for(i=1;i<n;i++) {
        loc = a[i];
        for(j=i-1;j>=0 && a[j]>loc;j--) {
            a[j+1] = a[j];
        }
        a[j+1] = loc;
    }
}