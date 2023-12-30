#include<stdio.h>
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
}