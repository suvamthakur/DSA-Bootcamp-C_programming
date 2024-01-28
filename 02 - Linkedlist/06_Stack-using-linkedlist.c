#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void push();
void pop();
void display();

struct Node {
    struct Node *next;
    int data;
}*top,*temp;

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
    temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL) {
        printf("\nOut of space");
    } else {
        int item;
        printf("\nEnter item: ");
        scanf("%d", &item);
        temp->data = item;
        if(top==NULL) {
            top = temp;
            top->next = NULL;
        } else {
            temp->next = top;
            top = temp;
        }
    }
}

void pop() {
    if(top==NULL) {
        printf("\nEmpty");
    } else {
        temp = top;
        top = top->next;
        temp->next = NULL;
        printf("\n%d is poped", temp->data);
        free(temp);
    }
}

void display() {
    if(top==NULL) {
        printf("\nEmpty");
    } else {
        temp = top;
        while(temp!=NULL) {
            printf("[%d]", temp->data);
            temp = temp->next;
            printf("\n");
        }
    }
}