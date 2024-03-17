#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();

int queue[20],rear=-1,front=-1, max;

int main() {
    int ch;
    printf("\nEnter size of the queue: ");
    scanf("%d", &max);
    while(1) {
        printf("\n1: Insert, 2: Delete, 3: Display, 4: Exit");
        printf("\nEnter your choice: ");
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
        }
    }
}

void insert() {
    if((rear+1)%max == front) {
        printf("\nFull");
    } else {
        int data;
        printf("\nEnter data: ");
        scanf("%d", &data);
        if(rear == -1) {
            rear = 0;
            front = 0;
        } else {
            rear = (rear+1)%max;
        }
        queue[rear] = data;
    }
}
void delete() {
    if(rear == -1) {
        printf("\nEmpty");
    } else {
        int del;
        del = queue[front];
        if(rear == front) {
            rear = -1;
            front = -1;
        } else {
            front = (front+1)%max;
        }
        printf("%d is deleted", del);
    }
}
void display() {
    if(rear == -1) {
        printf("\nEmpty");
    } else {
        if(front<=rear) {
            for(int i=front;i<=rear;i++) {
                printf("[%4d]", queue[i]);
            }
        } else {
            for(int i=front; i<=max-1;i++) {
                printf("[%4d]", queue[i]);
            }
            for(int i=0; i<=rear;i++) {
                printf("[%4d]", queue[i]);
            }
        }
    }
}