#include<stdio.h>
#include<stdlib.h>

void createNode();
void insertNode();
void insertFirst(int);
void insertGivenPosition(int);
void insertLast(int);
void deleteNode();
void deleteFirst();
void deleteGivenPosition();
void deleteLast();
void display();

struct node {
    int data;
    struct node* next;
}*head,*temp,*temp1,*temp2;

int main() {
    int ch;
    while(1) {
        printf("\n1: Create, 2: Insert, 3: Delete, 4: Display, 5: Exit");
        printf("\nEnter a no: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                createNode();
                break;
            case 2:
                insertNode();
                break;
            case 3:
                deleteNode();
                break;
            case 4:
                display();
                break;
            case 5:
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
        head=(struct node*)malloc(sizeof(struct node));
        head->data = item;
        head->next = head;
    }
    else {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=item;
        temp->next=head;
        temp1=head;
        while(temp1->next!=NULL) {
            temp1=temp1->next;
        }
        temp1->next = temp;
    }
}

void insertNode() {
    if(head==NULL) {
        printf("\nFirst Create a Node");
    } else {
        int ch,item;
        printf("\n1: Insert first, 2: Insert Given Position, 3: Insert Last");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        printf("\nEnter data: ");
        scanf("%d", &item);

        switch(ch) {
            case 1:
                insertFirst(item);
                break;
            case 2:
                insertGivenPosition(item);
                break;
            case 3:
                insertLast(item);
                break;
            case 4:
                exit(0);
        }
    }
}

void insertFirst(int item) {
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp1=head;
    while(temp1->next!=head) {
        temp1=temp1->next;
    }
    temp1->next = temp;
    temp->next = head;
    head = temp;
}
void insertGivenPosition(int item) {
    int pos;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp1=head;

    while(pos > 2) {
        temp1=temp1->next;
        pos--;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}
void insertLast(int item) {
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp1=head;
    while(temp1->next!=head) {
        temp1=temp1->next;
    }
    temp1->next = temp;
    temp->next = head;
}

void deleteNode() {
    if(head==NULL) {
        printf("\nEmpty list");
    } else {
        int ch;
        printf("\n1: Delete first, 2: Delete Given Position, 3: Delete Last");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                deleteFirst();
                break;
            case 2:
                deleteGivenPosition();
                break;
            case 3:
                deleteLast();
                break;
            case 4:
                exit(0);
        }
    }
}

void deleteFirst() {
    temp1 = head;
    while(temp1->next!=head) {
        temp1=temp1->next;
    }
    temp1->next = head->next;
    temp1=head;
    head=head->next;
    printf("%d is deleted", temp1->data);
    temp1->next=NULL;
    free(temp1);
}
void deleteGivenPosition() {
    int pos;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    temp1=head;
    while(pos > 2) {
        temp1=temp1->next;
    }
    temp1->next = temp2;
    temp1->next = temp2->next;
    printf("%d is deleted", temp2->data);
    temp2->next=NULL;
    free(temp2);
}
void deleteLast() {
    temp1 = head;
    while(temp1->next!=head) {
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next = temp1->next;
    printf("%d is deleted", temp1->data);
    temp1->next=NULL;
    free(temp1);
}

void display() {
    temp1=head->next;
    printf("--[%d]", head->data);
    while(temp1!=head) {
        printf("--[%d]", temp1->data);
        temp1=temp1->next;
    }
}