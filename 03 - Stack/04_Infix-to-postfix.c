#include<stdio.h>
#include<string.h>

char infixToPostfix(char[]);

int main() {
    char eq[] = "A+B*(C-(D/E+F))";
    char result;

    infixToPostfix(eq);
    printf("\nResult: %c", eq);
}

char infixToPostfix(char eq[]) {
    char stack[50];
    int top = -1;
    char result[50];
    int r = -1;
    for(int i=0;i<strlen(eq);i++) {
        switch(eq[i]) {
            case '+' : 
                if(stack[top] != "(" || top == -1) {
                    top++;
                    stack[top] = eq[i];
                }
                else {
                    r++;
                    result[r] = stack[top];
                    stack[top] = eq[i];
                }
            break;
            default:
                r++;
                top++;
                result[r] = stack[top];
        }
    }
}