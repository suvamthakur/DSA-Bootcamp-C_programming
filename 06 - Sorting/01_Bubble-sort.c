#include<stdio.h>
void bubblesort(int[], int);

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
    bubblesort(a,n);
    printf("\nSorted array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }
    return 0;
}

void bubblesort(int a[10], int n) {
    int temp,flag;
    for(int i=0;i<n;i++) {
        flag = 0;
        for(int j=0;j<n-i-1;j++) {
            if(a[j+1]<a[j]) {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                flag = 1;
            }
        }
        if(flag==0) {
            break;
        }
    }
}