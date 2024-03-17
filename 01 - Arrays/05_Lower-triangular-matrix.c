#include<stdio.h>

int main() {
    int n, matrix[50],lower[50];
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
    // Lower Trinagluar 
    int k=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(j<=i) {
                lower[k] = matrix[i*n+j];
                k++;
            }
        }
    }
    printf("\nLower triangluar matrix:\n");
    k=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(j<=i) {
                printf("%4d", lower[k]);
                k++;
            } else {
                printf("   0");
            }
        }
        printf("\n");
    }
}