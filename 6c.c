#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
    
};
struct node *head=NULL;
void enqueue(int value){
    struct node *newNode =(struct node *)malloc(sizeof(struct node *));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        struct node *temp =head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;  
    }
    printf("enqueued %d \n",value);
}
void dequeue(){
    if(head==NULL){
        printf("Queue Underflow\n");
        return;
    }
    struct node *temp=head;
    printf("dequeued %d\n",temp->data);
    head=head->next;
    free(temp);
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
    printf("1.enqueue 2.dequeue 3.display 4.exit \n");
    while(1){
        printf("enter choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter value:\n");
                    scanf("%d",&value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("exiting\n");
                    return 0;
            default: printf("invalid choice\n");
                     break;
        }
    }
return 0;

}