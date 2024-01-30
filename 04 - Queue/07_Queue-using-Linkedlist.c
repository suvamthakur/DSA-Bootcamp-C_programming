#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void insert();
void delete();
void display();

struct Node {
    struct Node *next;
    int data;
}*rear,*front,*temp;

int main() {
    int ch;
    while(1) {
        printf("\n1: Insert, 2: Delete, 3: Display, 4: Exit");
        printf("\nEnter a no: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
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

void insert() {
    temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL) {
        printf("\nFull");
    } else {
        int item;
        printf("\nEnter item: ");
        scanf("%d", &item);
        temp->data = item;

        if(rear==NULL) {
            rear = temp;
            front = temp;
        } else {
            rear->next = temp;
            rear = rear->next;
        }
        rear->next = NULL;
    }
}

void delete() {
    if(rear==NULL) {
        printf("\nEmpty");
    } else {
        temp = front;
        if(front == rear) {
            front = NULL;
            rear = NULL;
        } else {
            front = front->next;
        }
        temp->next = NULL;
        printf("%d is deleted", temp->data);
        free(temp);
    }
}

void display() {
    if(rear==NULL) {
        printf("\nEmpty");
    } else {
        temp = front;
        while(temp!=NULL) {
            printf("[%d]", temp->data);
            temp = temp->next;
        }
    }
}