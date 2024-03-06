#include<stdio.h>
void radixsort(int[], int);

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
    radixsort(a,n);
    printf("\nSorted array: ");
    for(int i=0;i<n;i++) {
        printf("%4d", a[i]);
    }
    return 0;
}

void radixsort(int a[10], int n) {
    int max = a[0];
    for(int i=1;i<n;i++) {
        if(max<a[i]) {
            max = a[i];
        }
    }
    for(int pos=1; max/pos > 0; pos=pos*10) {

        // Frequency count
        int count[10] = {0};
        for(int i=0;i<n;i++) {
            count[(a[i]/pos)%10]++;
        }

        // Find index
        for(int i=1;i<10;i++) {
            count[i] = count[i-1] + count[i];
        }

        // Sorting
        int b[n];
        for(int i=n-1;i>=0;i--) {
            b[ --count[(a[i]/pos)%10] ] = a[i];
        }

        // Copy b to a
        for(int i=0;i<n;i++) {
            a[i] = b[i];
        }
    }
}

// Time complexity = O(d*(n+k))  
// d = no of digit of max number, n = for loop for main array, k = for loop for count array
