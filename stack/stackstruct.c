#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct Stack {
    int top;
    int stack[MAX];
};
void pushs(struct Stack*,int);
int pops(struct Stack*);
void displays(struct Stack*);
void pushs(struct Stack *st, int ele)
{
    if(st->top==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        st->top = st->top + 1;
        st->stack[st->top] = ele;
    }
}
int pops(struct Stack *st)
{
    if(st->top==-1)
    {
        printf("Stack Underflow\n");
        return -1; // Return -1 to indicate stack is empty
    }
    else
    {
        int ele=st->stack[st->top];
        st->top = st->top - 1;
        return ele;
    }
}
void displays(struct Stack *st)
{
    if(st->top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Stack elements are:\n");
        for(int i=st->top; i>=0; i--)
        {
            printf("|%d|\n", st->stack[i]);
        }
    }
}
int main()
{
    int choice;
    int ele;
    struct Stack st; // Create an instance of the Stack structure
    st.top = -1; // Initialize the stack top to -1 to indicate an empty stack
    while (1)
    {
        printf("Enter Choice\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to push\n");
                scanf("%d", &ele);  
                pushs(&st,ele);
                break;
            case 2:
                ele = pops(&st);
                if (ele != -1) {
                    printf("Popped element: %d\n", ele);
                }
                break;
            case 3:
                displays(&st);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }  
    return 0;
}   
