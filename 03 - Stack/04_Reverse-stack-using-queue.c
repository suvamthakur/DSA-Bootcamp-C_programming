#include<stdio.h>
#include<stdlib.h>
void push();
int pop();
void display();
void reverse();

int stack[10], top = -1, max;
int rear = -1, front = -1;

int main() {
    int ch,item;;
    printf("\nEnter length of the stack: ");
    scanf("%d", &max);
    while(1) {
        printf("\n1: Push, 2: Pop, 3: Display, 4: Reverse, 5: Exit");
        printf("\nEnter a no: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nEnter an item: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong input");
        }
    }
}
void push(int item) {
    if(top == max-1) {
        printf("\nStack is full");
    } else {
        top++;
        stack[top] = item;
    }
}
int pop() {
    if(top == -1) {
        printf("\nEmpty stack");
    } else {
        int del;
        del = stack[top];
        top--;
        return del;
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
void reverse() {
    int Q[50];
    while(top != -1) {
        if(rear == -1) {
            rear = 0;
            front = 0;
        } else {
            rear = rear+1;
        }
        Q[rear]= pop();
    }
    for(int front=0;front<=rear;front++) {
        push(Q[front]);
    }
}