// Singly linkedlist
#include<stdio.h>
#include<stdlib.h>
void createNode();
void insertNode();
void insertFirst(int);
void insertGivenPosition(int);
void insertLast(int);
// void deleteNode();
// void deleteFirst();
// void deleteGivenPosition();
// void deleteLast();
// void search();
void display();

struct Node {
    int data;
    struct Node *next;
} *head, *temp, *temp2, *temp3, *tail;

int main() {
    int ch;
    while(1) {
        printf("\n1: Create, 2: Insert, 3: Delete, 4: Display, 5: Search, 6: Exit");
        printf("\nEnter a no: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                createNode();
                break;
            case 2:
                insertNode();
                break;
            // case 3:
            //     deleteNode();
            //     break;
            case 4:
                display();
                break;
            // case 5:
            //     search();
            //     break;
            case 6:
                exit(0);
            default:
                printf("\nWrong input.");
                break;
        }
    }
}

void createNode() {
    int item;
    printf("\nEnter an item: ");
    scanf("%d", &item);
    if(head==NULL) {
        head = (struct Node*)malloc(sizeof(struct Node));
        head->data = item;
        head->next = NULL;
        tail = head;
    }
    else {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = item;
        temp->next = NULL;
        temp2 = head;
        while(temp2->next!=NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp2 = temp;
        tail = temp;
    }
}
void insertNode() {
    if(head==NULL) {
        printf("\nEmpty list");
    } else {
        int ch, data;
        printf("\n 1: InsertFirst, 2: InsertGivenPosition, 3: InsertLast, 4: Exit");
        printf("\nEnter a no: ");
        scanf("%d", &ch);

        printf("\nEnter an item: ");
        scanf("%d", &data);
        switch(ch) {
            case 1:
                insertFirst(data);
                break;
            case 2:
                insertGivenPosition(data);
                break;
            case 3:
                insertLast(data);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nWrong input");
                break;
        }
    }
}

void insertFirst(int data) {
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}
void insertGivenPosition(int data) {
    int p;
    printf("\nEnter position: ");
    scanf("%d", &p);
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp2 = head;
    while(p>2) {
        temp2 = temp2->next;
        p--;
    }
    temp3 = temp2->next;
    temp2->next = temp;
    temp->next = temp3;
}
void insertLast(int data) {
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}


void display() {
    if(head==NULL) {
        printf("\nEmpty list");
    } else {
        temp2 = head;
        while(temp2!=NULL) {
            printf(" [%d] ", temp2->data);
            temp2 = temp2->next;
        }
    }
}