#include<stdio.h>
void selectionsort(int[], int);

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
    selectionsort(a,n);
    printf("\nSorted array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }
    return 0;
}
void selectionsort(int a[10], int n) {
    int min,flag,p;
    for(int i=0;i<n;i++) {
        flag = 0;
        min = a[i];
        p=i;
        for(int j=i+1;j<n;j++) {
            if(a[j]<min) {
                min = a[j];
                p = j;
                flag = 1;
            }
        }
        if(flag==0) {
            break;
        }
        a[p] = a[i];
        a[i] = min; 
    }
}