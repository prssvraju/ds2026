#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=-1;
int stack[MAX];
void push(int ele)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        top=top+1;
        stack[top]=ele;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return -1; // Return -1 to indicate stack is empty
    }
    else
    {
        int ele=stack[top];
        top=top-1;
        return ele;
    }
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Stack elements are:\n");
        for(int i=top; i>=0; i--)
        {
            printf("|%d|\n", stack[i]);
        }
    }
}
int main()
{
    int choice;
    int ele;
    while (1)
    {
        printf("Enter Choice\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to push\n");
                scanf("%d", &ele);  
                push(ele);
                break;
            case 2:
                ele = pop();
                if (ele != -1) {
                    printf("Popped element: %d\n", ele);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }  
    return 0;
}   
