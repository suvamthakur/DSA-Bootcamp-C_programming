#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();

int stack[10], top = -1, max = 10;

int main() {
    int ch;
    while(1) {
        printf("\n1: Push, 2: Pop, 3: Display, 4: Exit");
        printf("\nEnter a no: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong input");
        }
    }
}

void push() {
    if(top == max-1) {
        printf("\nStack is full");
    } else {
        int item;
        printf("\nEnter an item: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
    }
}

void pop() {
    if(top == -1) {
        printf("\nEmpty stack");
    } else {
        int del;
        del = stack[top];
        top--;
        printf("%d is popped", del);
    }
}

void display() {
    if(top == -1) {
        printf("\nEmpty");
    } else {
        for(int i=top;i>=0;i--) {
            printf("[%d]", stack[i]);
            printf("\n");
        }
    }
}