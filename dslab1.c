#include<stdio.h>
#define SIZE 10
void pop();
void push(int);
void display();
void peek();
int stack[SIZE],top=-1;
int main(){
    while(1){
        int choice;
        printf("enter ur choice-(1)-push,(2)-pop,(3)-peek,(4)-display\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                int element ;
                printf("enter element:\n");
                scanf("%d",&element);
                push(element);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                peek();
                break;
            }
            case 4:{
                display();
                break;
            }
        }
    }
    return 0;
}
void push(int new){
    if(top==SIZE){
        printf("StackOverflow, stack is full\n");
    }
    else{
        top++;
        stack[top]=new;
        printf("pushed succesfully\n");
    }
}
void pop(){
    if(top==-1){
        printf("StackUnderflow, stack is empty\n");
    }
    else{
        int x=stack[top];
        top--;
        printf("popped - %d\n",x);
    }
}
void peek(){
    if(top==-1){
        printf("StackUnderflow, stack is empty\n");
    }
    else{
        int x=stack[top];
        printf("peeked - %d\n",x);
    }
}
void display(){
    int i;
     if(top==-1){
        printf("StackUnderflow, stack is empty\n");
    }
    else{
        printf("Stack Display\n");
        for(i=0;i<=top;i++){
            printf("%d\n",stack[top-i]);
        }
    }
}