#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void createNode();
void deleteNode();
void display();

struct node {
    struct node *pre;
    int data;
    struct node *next;
}*head,*tail,*temp;

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

void createNode() {
    int item;
    printf("\nEnter an item: ");
    scanf("%d", &item);

    if(head==NULL) {
        head = (struct node*)malloc(sizeof(struct node));
        head->data = item;
        head->pre = NULL;
        head->next = NULL;
        tail=head;
    }
    else {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = item;
        temp->next = NULL;
        temp->pre = tail;
        tail->next = temp;
        tail = tail->next;
    }
}

void deleteNode() {
    if(head==NULL) {
        printf("\nEmpty list");
    }
    else {
        temp = head;
        head = head->next;
        head->pre = NULL;
        temp->next = NULL;
        printf("\n%d is deleted", temp->data);
        free(temp);
    }
}

void display() {
    if(head==NULL) {
        printf("\nEmpty list");
    }
    else {
        temp = head;
        while(temp!=NULL) {
            printf("[%d] ", temp->data);
            temp = temp->next;
        }
    }
}