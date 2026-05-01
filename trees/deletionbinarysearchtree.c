/* * C program to implement the Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>
// structure of a node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *nodeptr; 
// globally initialized root pointer
nodeptr root = NULL;
 
// function prototyping
nodeptr create_node(int);
nodeptr insert(nodeptr, int);
nodeptr del(nodeptr, int);
int search(nodeptr, int);
void inorder(nodeptr);
void postorder();
void preorder();
nodeptr smallest_node(nodeptr);
nodeptr largest_node(nodeptr);
int get_data();
 
int main()
{
    int ch;
    int data;
    nodeptr result = NULL;
 
    while (1)
    {
        printf("\n\n------- Binary Search Tree ------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Get Larger Node Data");
        printf("\n5. Get smaller Node data");
        printf("\n\n-- Traversals --");
        printf("\n\n6. Inorder ");
        printf("\n7. Post Order ");
        printf("\n8. Pre Oder ");
        printf("\n9. Exit");
 
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &ch);
        printf("\n");
 
        switch(ch)
        {
            case 1:	data = get_data();
                	root=insert(root, data);
                	break;
            case 2:	data = get_data();
                	root = del(root, data);
                	break;
            case 3:	data = get_data();
                	if (search(root,data) == 1)
                		printf("\nData was found!\n");
                    else
                        printf("\nData does not found!\n");
                    break;
            case 4: result = largest_node(root);
                	if (result != NULL)
                        printf("\nLargest Data: %d\n", result->data);
                    break;
            case 5:	result = smallest_node(root);
                	if (result != NULL)
                        printf("\nSmallest Data: %d\n", result->data);
                    break;
 
            case 6: inorder(root);
                	break;
            case 7:	postorder(root);
                	break;
            case 8:	preorder(root);
                	break;
            case 9:	exit(0);
			
		}
	}
    return 0;
}
 
// creates a new node
nodeptr create_node(int data)
{
    nodeptr new_node = (nodeptr)malloc(sizeof(struct node));
 
    if (new_node == NULL)
    {
        printf("\nMemory for new node can't be allocated");
        return NULL;
    }
 
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
 
    return new_node;
}
// inserts the data in the BST
nodeptr insert(nodeptr root, int data)
{
    nodeptr new_node = create_node(data);
    if (root == NULL)
    {
    	root = new_node;
        printf("\n* node having data %d was inserted\n", data);
        return root;
    }
    if (data < root->data)
    {
     	root->left = insert (root->left, data);
    	}
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
 
        printf("\n* node having data %d was inserted\n", data);
	return root;
}
// deletes the given key node from the BST
nodeptr del (nodeptr root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = del (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = del(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            nodeptr temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            nodeptr temp = root->left;
            free(root);
            return temp;
        }
        nodeptr temp = smallest_node(root->right);
        root->data = temp->data;
        root->right = del (root->right, temp->data);
    }
    return root;
 
}
 
// search the given key node in BST
int search(nodeptr root, int key)
{
   	if(root==NULL)
	   return -1;
	if(key<root->data)
		search(root->left, key);
	else if(key>root->data)
		search(root->right, key);
	else return 1; 
     
}
 
// finds the node with the smallest value in BST
nodeptr smallest_node(nodeptr root)
{
    nodeptr curr = root;
    while (curr != NULL && curr->left != NULL)
   {
        curr = curr->left;
    }
    return curr;
}
 
// finds the node with the largest value in BST
nodeptr largest_node(struct node *root)
{
    nodeptr curr = root;
    while (curr != NULL && curr->right != NULL)
    {
        curr =  curr->right;
    }
    return curr;
}
 
// inorder traversal of the BST
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",  root->data);
    inorder(root->right);
}
 
// preorder traversal of the BST
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
 
// postorder travsersal of the BST
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
 
// getting data from the user
int get_data()
{
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}
