#include<stdio.h>

int main() {
    int n, matrix[50];
    printf("\nEnter n: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("\nEnter element: ");
            scanf("%d", &matrix[i*n+j]);
        }
    }
    printf("\nGiven matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%4d", matrix[i*n+j]);
        }
        printf("\n");
    }
    printf("\nDiagonal matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) {
                printf("%4d", matrix[i*n+j]);
            } else {
                printf("   0");
            }
        }
        printf("\n");
    }
}