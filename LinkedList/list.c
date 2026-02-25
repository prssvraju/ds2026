#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* getNode();
void display(struct node*);
struct node* insert(struct node*);
struct node* insert(struct node * head)
{
    int ch;
    struct node *newnode,*temp;
    if(head!=NULL)
    {
        newnode =getNode();
        printf("enter New node value");
        scanf("%d",&newnode->data);
        printf("\n1.Begning\n2.Ending\n3.position");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    newnode->next=head;
                    head=newnode;
                    break;
            case 2:
                    temp=head;
                    while (temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=newnode;
                    
                    
                    break;
            case 3:
                    printf("Position");
                    break;
            default:
                    printf("Invalid choice");
                    break;

        }
    }
    else
    {
        printf("List is empty");
    }
    return head;
}
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

  return head->next;

}
int main()
{
    struct node *head=NULL;
    // 
    // 
    int ch;

    while (1)
    {
        printf("\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   head=createList();
                   break;
            case 2:
                    head=insert(head);
                    break;
            case 3:
                    printf("==Delete==");
                    break;
            case 4:
                    display(head);
                    break;
            case 5:
                    exit(0);
                    break;
            default :
                    printf("==Invalid option==");
                    break;
        }
       
    }
    
}