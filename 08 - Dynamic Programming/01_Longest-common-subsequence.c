#include<stdio.h>
#include<string.h>

int lcs(char[], char[], int, int); 

int main()
{
    char s1[100], s2[100];
    int len1,len2;
    printf("Enter first & Second string: ");
    scanf("%s %s", &s1, &s2);
    
    // Length of strings
    for(len1=0;s1[len1]!='\0';len1++);
    for(len2=0;s2[len2]!='\0';len2++);

    int result = lcs(s1,s2,len1,len2);

    printf("\nString 1: %s", s1);
    printf("\nString 2: %s", s2);

    printf("\nLength of LCS is %d", result);
}

int lcs(char s1[], char s2[], int len1, int len2) {
    int dp[len1][len2];

    for(int i=0;i<len1;i++) {
        dp[i][0] = 0;
    }
    for(int i=1;i<=len1;i++) {
        for(int j=1;j<=len2;j++) {
            dp[0][j] = 0;

            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }

    }
    return dp[len1][len2];
}