#include<stdio.h>
int GCD(int, int);

int main() {
    int x,y;
    printf("\nEnter two no: ");
    scanf("%d %d", &x, &y);
    int p = GCD(x,y);
    printf("\nGCD: %d", p);
    return 0;
}

int GCD(int x, int y) {
    if(x==0 && y==0) {
        return 0;
    }
    else if(x!=0 && y==0) {
        return x;
    }
    else if(x==0 && y!=0) {
        return y;
    } else {
        return GCD(y%x, x);
    }
}