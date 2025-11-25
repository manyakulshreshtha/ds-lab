#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};  
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL){
        temp = temp->next;}
    temp->next = newNode;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void sort(struct Node* head) {
    if (head == NULL){
        printf("empty list no sort\n");
        return;}
    struct Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void reverse(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
struct Node* concat(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}
int main() {
    struct Node *list1 = NULL, *list2 = NULL;

    int choice, value;
    printf("\n---- MENU ----\n");
    printf("1. Insert into List 1 2. Insert into List 2 3. Display List 1 4. Display List 2 5. Sort List 1 6. Reverse List 1 7. Concatenate List 1 and List 2 8. Exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list1, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list2, value);
                break;

            case 3:
                printf("List 1: ");
                display(list1);
                break;

            case 4:
                printf("List 2: ");
                display(list2);
                break;

            case 5:
                sort(list1);
                display(list1);
                printf("List 1 Sorted.\n");
                break;

            case 6:
                reverse(&list1);
                display(list1);
                printf("List 1 Reversed.\n");
                break;

            case 7:
                list1 = concat(list1, list2);
                printf("Lists concatenated. Now List 1 is:\n");
                display(list1);
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
