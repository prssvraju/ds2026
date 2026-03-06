#include<stdio.h>
#include<stdlib.h>
struct node
{
    int cof,exp;
    struct node *next;
};
struct node* insert(struct node*,int,int);
struct node*getNode();
struct node* create();
void display(struct node *);
struct node *getNode()
{
    struct node *newnode;
    newnode= (struct node *)malloc(sizeof(struct node));
    newnode->cof=0;
    newnode->exp=0;
    newnode->next=NULL;
    return newnode;
}

struct node* create()
{
    int i,cof,exp,n;
    struct node *phead=NULL;
    printf("Enter num of terms");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        printf("Enter %d tem cof and exp",i+1);
        scanf("%d%d",&cof,&exp);
        phead=insert(phead,cof,exp);
    }
    return phead;
}
struct node * insert(struct node *phead,int cof, int exp)
{
    struct node * newnode,*temp;
    newnode=getNode();
    newnode->exp=exp;
    newnode->cof=cof;
    if(phead==NULL||exp>phead->exp)
    {
        newnode->next=phead;
        phead=newnode;
    }
    else
    {
        temp=phead;
        while(temp->next!=NULL||exp<temp->exp)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return phead;
}
void display(struct node *phead)
{
    struct node*temp;
    temp=phead;
    while(temp!=NULL)
    {
        printf("%dX%d+",temp->cof,temp->exp);
        temp=temp->next;
    }

}
int main()
{
    struct  node *phead;
    phead=create();
    display(phead);   
}
