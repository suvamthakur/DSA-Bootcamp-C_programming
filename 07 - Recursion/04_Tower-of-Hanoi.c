#include<stdio.h>
void TOH(int, int, int, int);

int main() {
    int n,s=1,v=2,d=3;
    printf("\nEnter n: ");
    scanf("%d", &n);
    TOH(n,s,d,v);
    return 0;
}

void TOH(int n, int s, int d, int v) {
    if(n>0) {
        TOH(n-1,s,v,d);
        printf("\nMove %d to %d", s,d);
        TOH(n-1,v,d,s);
    }
}