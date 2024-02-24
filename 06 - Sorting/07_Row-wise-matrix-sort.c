#include<stdio.h>
void sort(int[][10], int);
int main()
{
    int x[10][10],n;
    
    printf("Enter n: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)   
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter array element: ");
            scanf("%d", &x[i][j]);
        }
    } 
    
    printf("\n Given array:\n");
    for(int i=0;i<n;i++)   
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d", x[i][j]);
        }
        printf("\n");
    }

    sort(x,n);

    printf("\nRow wise sorted matrix: \n");
    for(int i=0;i<n;i++)   
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d", x[i][j]);
        }
        printf("\n");
    }
}

void sort(int a[10][10], int n) {
    int temp;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<n-j-1;k++) {

                if(a[i][k]>a[i][k+1]) {
                    temp = a[i][k];
                    a[i][k] = a[i][k+1];
                    a[i][k+1] = temp;
                }
            }

        }
    } 
}