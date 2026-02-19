#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* getNode();
void display(struct node*);
void display(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
struct node* getNode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=0;
    newnode->next=NULL;
    return newnode;
}

struct node* createList();


struct node* createList()
{
  struct node *head,*first,*newnode;   
  first=getNode();
  head=first;
  newnode=getNode();
  printf("enter value");
  scanf("%d",&newnode->data);
  while(newnode->data!=-12)
  { 
    first->next=newnode;
    first=newnode;
    newnode=getNode();
    printf("enter value");
    scanf("%d",&newnode->data);
  }

  return first;

}
int main()
{
    struct node *head;
    head=createList();
    display(head);
}