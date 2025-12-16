#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;  
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void createList() {
    int n, value;
    printf("How many nodes to create? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}
void insertAtBeginning() {
    int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd() {
    int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);

    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
void insertAtPosition() {
    int value, pos, count = 1;
    printf("Enter value: ");
    scanf("%d", &value);
    printf("Enter position: ");
    scanf("%d", &pos);

    struct Node* newNode = createNode(value);

    if (pos == 1) {   
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void displayList() {
    struct Node* temp = head;
   
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice;
     printf("\n MENU \n");
        printf("1. Create 2. Insert at Beginning 3. Insert at End 4. Insert at Position 5. Display List 6. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createList(); break;
            case 2: insertAtBeginning(); break;
            case 3: insertAtEnd(); break;
            case 4: insertAtPosition(); break;
            case 5: displayList(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid Choice!\n");
        }
    } while(choice != 6);

    return 0;
}
