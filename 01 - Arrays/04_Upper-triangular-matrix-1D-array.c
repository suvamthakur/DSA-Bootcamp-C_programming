#include<stdio.h>

int main() {
    int n, matrix[50],upper[50];
    printf("\nEnter n: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("\nEnter element: ");
            scanf("%d", &matrix[i*n+j]);
        }
    }
    printf("\nGiven matrix: \n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%4d", matrix[i*n+j]);
        }
        printf("\n");
    }
    // Upper Trinagluar 
    int k=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(j>=i) {
                upper[k] = matrix[i*n+j];
                k++;
            }
        }
    }
    printf("\nUpper triangluar matrix:\n");
    k=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(j>=i) {
                printf("%4d", upper[k]);
                k++;
            } else {
                printf("   0");
            }
        }
        printf("\n");
    }
}