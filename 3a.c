#include<stdio.h>
#define SIZE 50 
int queue[SIZE];
int front=-1,rear=-1;
void insert(int x){
    if(rear==SIZE-1){
        printf("Overflow in queue cant insert\n");
    }
    if(front==-1){
        front=0;
    }
    queue[++rear]=x;
    printf("inserted %d into queue",x);
}
void delete(){
    if(front==-1||front>rear){
        printf("Underflow in queue , empty\n");
    }
    if(front>rear){
        front=rear=-1;
    }
    else{int deleted=queue[front++];
    printf("%d is deleted\n",deleted);
}}
void display(){
    if(front==-1){
        printf("Underflow , empty queue\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
        printf("succesfully displayed\n");
    }
}
int main(){
    int choice,value;
    while(1){
         printf("enter your choice :(1)-insert (2)-delete (3)-display (4)-exit");
         scanf("%d",&choice);
         switch (choice)
         {
         case 1:
            printf("enter values\n");
            scanf("%d",&value);
            insert(value);
            break;
        case 2:
            delete();
            break;
        case 3:
             display();
             break;
        case 4:
            printf("exiting\n");
            return 0;
         default:
            printf("invalid choice\n");
            break;
         }
    }
    return 0;
    
}