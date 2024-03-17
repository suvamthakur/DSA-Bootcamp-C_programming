#include<stdio.h>

int max(int a, int b) {
    return (a>b)?a:b;
}

int knapsack(int w[10], int p[10], int n, int c) {
    int ks[n+1][c+1],i,j;
    for(j=0;j<=c;j++) {
        ks[0][j] = 0;
    }
    for(i=1;i<=n;i++) {
        ks[i][0] = 0;
        for(j=1;j<=c;j++) {
            if(j>=w[i-1]) {
                ks[i][j] = max( ks[i-1][j], p[i-1] + ks[i-1][j-w[i-1]] );
            } else {
                ks[i][j] = ks[i-1][j];
            }
        }
    }
    return ks[n][c];
}

int main() {
    int c, w[10], p[10],n;
    printf("\nEnter capacity: ");
    scanf("%d", &c);
    printf("\nEnter no of items: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("\nEnter weight and profit for item %d: ", i+1);
        scanf("%d %d", &w[i], &p[i]);
    }
    int profit = knapsack(w,p,n,c);
    printf("\nMaximum profit: %d", profit);
}