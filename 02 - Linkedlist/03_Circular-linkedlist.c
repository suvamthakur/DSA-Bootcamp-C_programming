#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void createNode();
void deleteNode();
void display();

struct node {
    int data;
    struct node *next;
}*head,*temp,*temp2;

int main()
{
    int ch;
    while(1) {
        printf("\n1: Create, 2: Delete, 3: Display, 4: Exit");
        printf("\nEnter a no: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                createNode();
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
        }
    }
}

// Inserting from last
void createNode() {
    int item;
    printf("\nEnter an item: ");
    scanf("%d", &item);

    if(head==NULL) {
        head = (struct node*)malloc(sizeof(struct node));
        head->data = item;
        head->next = head;
    }
    else {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = item;
        temp->next = head;
        temp2 = head;
        while(temp2->next!=head) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

// Deleting the first node
void deleteNode() {
    if(head==NULL) {
        printf("\nEmpty list");
    }
    else {
        temp2 = head;
        head = head->next;
        temp->next = head;
        temp2->next = NULL;
        printf("\n%d is deleted", temp2->data);
        free(temp2);
    }
}

void display() {
    if(head==NULL) {
        printf("\nEmpty list");
    }
    else {
        temp2 = head;
        while(temp2->next!=head) {
            printf("[%d] ", temp2->data);
            temp2 = temp2->next;
        }
        printf("[%d] ", temp2->data);
    }
}