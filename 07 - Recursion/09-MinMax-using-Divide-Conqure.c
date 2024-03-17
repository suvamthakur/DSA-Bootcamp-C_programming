#include<stdio.h>

void minMax(int a[], int l, int h, int *min, int *max) {
    int lmin,lmax,rmin,rmax;
    if(l==h) {  // if there is one element
        *max=a[l];
        *min=a[l];
        return;
    }
    else if((l+1)==h) {  // if there are two elements
        if(a[l]>a[h]) {
            *max = a[l];
            *min = a[h];
        } else {
            *max = a[h];
            *min = a[l];
        }
        return;
    } 
    else {
        int mid = (l+h)/2;
        minMax(a,0,mid,&lmin,&lmax);
        minMax(a,mid+1,h,&rmin,&rmax);

        *min = (lmin<rmin)? lmin : rmin; 
        *max = (lmax>rmax)? lmax : rmax; 
    }
}

int main() {
    int a[] = {7,1,6,2,3,4,13,8};
    int n = sizeof(a)/sizeof(a[0]);
    int min, max;
    minMax(a,0,n-1,&min,&max);

    printf("Minimum element is %d: ", min); 
    printf("Maximum element is %d: ", max);
}