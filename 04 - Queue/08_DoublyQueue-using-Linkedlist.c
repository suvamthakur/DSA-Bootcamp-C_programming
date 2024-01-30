#include<stdio.h>
#include<stdlib.h>

void insert();
void insertrear();
void insertfront();
void deleteNode();
void deleterear();
void deletefront();
void display();

struct node {
    int data;
    struct node *next;
}*front,*rear,*temp,*temp2;

int main() {
    int ch;
    while(1) {
        printf("\n1: create 2: delete 3: display 4: exit");
        printf("\nEnter a no: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                insert();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong input");
                break;
        }
    }
}

void insert() {
    int c;
    printf("\n1: Insert front 2: Insert last");
    printf("\nEnter a no: ");
    scanf("%d", &c);
    switch(c) {
        case 1:
            insertfront();
            break;
        case 2:
            insertrear();
            break;
        default:
            printf("\nWrong input");
            break;
    }
}
void insertfront() {
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL) {
        printf("\nFull");
    }else {
        int item;
        printf("\nEnter an item: ");
        scanf("%d", &item);
        temp->data = item;
        if((rear==NULL) && (front==NULL)) {
            rear = temp;
            front = temp;
            front->next = NULL;
        }else {
            temp->next = front;
            front = temp;
        }
    }
}
void insertrear() {
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL) {
        printf("\nFull");
    }else {
        int item;
        printf("\nEnter an item: ");
        scanf("%d", &item);
        temp->data = item;
        temp->next = NULL;
        if((rear==NULL) && (front==NULL)) {
            rear = temp;
            front = temp;
        }else {
            rear->next = temp;
            rear = temp;
        }
    }
}
void deleteNode() {
    int c1;
    printf("\n1: Delete front, 2: Delete last");
    printf("\nEnter a no: ");
    scanf("%d", &c1);
    switch(c1) {
        case 1:
            deletefront();
            break;
        case 2:
            deleterear();
            break;
        default:
            printf("\nWrong input");
    }
}
void deletefront() {
    if(front==NULL) {
        printf("\nEmpty");
    }else {
        temp = front;
        if(rear==front) {
            rear = NULL;
            front = NULL;
        }else {
            front = front->next;
        }
        temp->next = NULL;
        printf("%d is deleted", temp->data);
        free(temp);
    }
}
void deleterear() {
    if(front==NULL) {
        printf("\nEmpty");
    }else {
        temp = front;
        if(rear==front) {
            rear = NULL;
            front = NULL;
        }else {
            while(temp->next!=NULL) {
                temp2 = temp;
                temp = temp->next; 
            }
            rear = temp2;
            rear->next = NULL;
        }
        printf("%d is deleted", temp->data);
        free(temp);
    }
}
void display() {
    if(rear==NULL) {
        printf("\nEmpty");
    }else {
        temp = front;
        while(temp != NULL) {
            printf(" [%d]", temp->data);
            temp = temp->next;
        }
    }
}
