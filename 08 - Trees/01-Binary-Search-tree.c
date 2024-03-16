#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


int item;

void createnode();
void insertnode();
struct node* deletenode(struct node*, int item);
struct node* preorder(struct node*);
struct node* inorder(struct node*);
struct node* postorder(struct node*);

struct node {
    int data;
    struct node* left;
    struct node* right;
}*root,*temp,*temp1;

struct node* temp2 = NULL;

int main() {
    int ch;
    while(1) {
        printf("\nPress 1 for Create Node"
                "\nPress 2 for Insert Node"
                "\nEnter 3 for Pre-order traversal"
                "\nEnter 4 for In-order traversal"
                "\nEnter 5 for Post-order traversal"
                "\nEnter 6 for Delete node"
                "\nEnter 7 for exit"
                "\nEnter here: "
        );
        scanf("%d", &ch);
        switch(ch) {
            case 1: 
                createnode();
                break;
            case 2:
                insertnode();
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                printf("\nEnter node to be deleted: ");
                scanf("%d",&item);
                root = deletenode(root, item);
                break;
            case 7:
                exit(0);
        }
    }
}

void position(struct node* temp1, struct node* temp, int item) {
    while(temp1->left!=NULL && item < temp1->data) {
        temp1=temp1->left;
    }
    while(temp1->right!=NULL && item > temp1->data) {
        temp1=temp1->right;
    }
    if(item < temp1->data) {
        temp1->left = temp;
    } else {
        temp1->right = temp;
    }
}

void createnode() {
    int item;
    printf("\nEnter data: ");
    scanf("%d", &item);
    if(root == NULL) {
        root = (struct node*)malloc(sizeof(struct node));
        root->data=item;
        root->left=NULL;
        root->right=NULL;
        temp1=root;
    }   
}

void insertnode() {
    if(root==NULL) {
        printf("create root node");
    }
    else {
        int item;
        printf("\nEnter data: ");
        scanf("%d", &item);

        temp = (struct node*)malloc(sizeof(struct node));
        temp->data=item;
        temp->left=NULL;
        temp->right=NULL;

        if(item < root->data) {
            position(root,temp, item);
        }
        else {
            position(root,temp, item);
        }
    }
}

struct node* preorder(struct node* temp1) {
    if(temp1==NULL) {
        return NULL;
    }
    printf("%4d", temp1->data);
    preorder(temp1->left);
    preorder(temp1->right);
}
struct node* inorder(struct node* temp1) {
    if(temp1==NULL) {
        return NULL;
    }
    inorder(temp1->left);
    printf("%4d", temp1->data);
    inorder(temp1->right);
}
struct node* postorder(struct node* temp1) {
    if(temp1==NULL) {
        return NULL;
    }
    postorder(temp1->left);
    postorder(temp1->right);
    printf("%4d", temp1->data);
}

// struct node* findmax(struct node* maxnode) {
//     if(maxnode->right!=NULL) {
//         maxnode = maxnode->right;
//     }
//     return maxnode;
// }

// struct node* deletenode(struct node* temp1) {
//     if(root==NULL) {
//         printf("\nEmpty tree");
//     }
//     else {
//         int item;
//         printf("\nEnter node to be deleted: ");
//         scanf("%d", item);
//         while(temp1->left!=NULL && item < temp1->data) {
//             temp2=temp1;
//             temp1=temp1->left;
//         }
//         while(temp1->right!=NULL && item > temp1->data) {
//             temp2=temp1;
//             temp1=temp1->right;
//         }
//         if(temp2->data > temp1->data) {
//             if(temp1->left==NULL) {
//                 temp2->left = temp1->right;
//             } else if(temp1->right==NULL) {
//                 temp2->left = temp1->left;
//             }
//             else {
//                 struct node* max = findmax(temp1->left);
//                 temp2->left = temp1->left;
//                 max->right = temp1->right;
//                 printf("%d is deleted", temp1->data);
//                 free(temp1);
//             }
//         }
//         else {
//             if(temp1->left==NULL) {
//                 temp2->right = temp1->right;
//             } else if(temp1->right==NULL) {
//                 temp2->right = temp1->left;
//             }
//             else {
//                 struct node* max = findmax(temp1->left);
//                 temp2->right = temp1->left;
//                 max->right = temp1->right;
//                 printf("%d is deleted", temp1->data);
//                 free(temp1);
//             }
//         }
//     }
// }

struct node* find_min(struct node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
struct node* deletenode(struct node* node, int data) {
    if (node == NULL) {
        printf("\nEmpty tree");
        return node;
    }
    if (data < node->data) {
        node->left = deletenode(node->left, data);
    } else if (data > node->data) {
        node->right = deletenode(node->right, data);
    } else {
        if (node->left == NULL) {
            struct node* temp = node->right;
            printf("%d is deleted", node->data);
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct node* temp = node->left;
            printf("%d is deleted", node->data);
            free(node);
            return temp;
        }
        struct node* temp3 = find_min(node->right);
        node->data = temp3->data;
        node->right = deletenode(node->right, temp3->data);
    }
    return node;
}