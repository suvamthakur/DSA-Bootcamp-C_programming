#include<stdio.h>
void LS(int[], int, int);

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
    LS(a,n,v);
    return 0;
}

void LS(int a[10], int n, int v) {
    int flag = 0,p;
    for(int i=0;i<n;i++) {
        if(a[i]==v) {
            flag = 1;
            p = i+1;
            break;
        }
    }
    if(flag==1) {
        printf("\nElement fount at position %d", p);
    } else {
        printf("\nElement not found");
    }
}