#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int data;
    struct listnode* left;
    struct listnode* right;
} Node;

Node* createNode(int val) {
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;   
}

void insertnode(Node* newnode, Node* root) {
    if (newnode->data < root->data) {
        if (root->left != NULL)
            insertnode(newnode, root->left);
        else
            root->left = newnode;
    } else {
        if (root->right != NULL)
            insertnode(newnode, root->right);
        else
            root->right = newnode;
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    printf("\n1. Insert\n2. Preorder\n3. Postorder\n4. Inorder\n5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                
                Node* newnode = createNode(value);

                if (root == NULL) {     
                    root = newnode;}
                else{
                    insertnode(newnode, root);}
                    break;

            case 2:
                preorder(root);
                printf("\n");
                break;

            case 3:
                postorder(root);
                printf("\n");
                break;

            case 4:
                inorder(root);
                printf("\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
