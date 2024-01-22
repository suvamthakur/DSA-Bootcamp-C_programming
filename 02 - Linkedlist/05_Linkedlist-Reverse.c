#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void createNode();
void deleteNode();
void display();
void reverse();


struct node {
    int data;
    struct node *next;
}*head,*temp,*temp2, *preNode, *nextNode;

int main()
{
    int ch;
    while(1) {
        printf("\n1: Create, 2: Delete, 3: Reverse, 4: Display, 5: Exit");
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
                reverse();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong input");
        }
    }
}

// Using three poniter (preNode, nextNode, temp2 = currentNode)
void reverse() {
    temp2 = head;
    while(temp2!=NULL) {
        nextNode = temp2->next;
        temp2->next = preNode;
        preNode = temp2;
        temp2 = nextNode;
    }
    head = preNode;
    preNode = NULL;
    printf("\nList reversed");
}

void createNode() {
    int item;
    printf("\nEnter an item: ");
    scanf("%d", &item);

    if(head==NULL) {
        head = (struct node*)malloc(sizeof(struct node));
        head->data = item;
        head->next = NULL;
    }
    else {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = item;
        temp->next = NULL;
        temp2 = head;
        while(temp2->next!=NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

void deleteNode() {
    if(head==NULL) {
        printf("\nEmpty list");
    }
    else {
        temp2 = head;
        head = head->next;
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
        while(temp2!=NULL) {
            printf("[%d] ", temp2->data);
            temp2 = temp2->next;
        }
    }
}