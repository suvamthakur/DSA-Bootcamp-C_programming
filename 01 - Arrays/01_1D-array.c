#include<stdio.h>
void arr(int[], int);
int main()
{
    int a[10],n;

    printf("Enter no of element: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        printf("Enter array element: ");
        scanf("%d", &a[i]);
    }
    
    printf("\nGiven Array: \n");
    for(int i=0;i<n;i++)
    {
        printf("%4d", a[i]);
    }
    return 0;
}