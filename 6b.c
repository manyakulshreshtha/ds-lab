#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
    
};
struct node *head=NULL;
void push(int value){
    struct node *newNode =(struct node *)malloc(sizeof(struct node *));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Pushed %d \n",value);
}
void pop(){
    if(head==NULL){
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp=head;
    printf("popped %d\n",temp->data);
    head=head->next;
    free(temp);
}
void peek(){
    if(head==NULL){
        printf("Stack Underflow\n");
        return;
    }
    printf("top->%d\n",head->data);
}
void display(){
    if(head==NULL){
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");   
}
int main(){
    int choice,value;
    printf("\nMENU\n");
    printf("1.push 2.pop 3.peek 4.display 5.exit\n");
    while(1){
        printf("enter choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter value:\n");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: printf("exiting\n");
                    return 0;
            default: printf("invalid choice\n");
                     break;
        }
    }
return 0;

}