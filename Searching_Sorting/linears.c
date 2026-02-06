#include<stdio.h>
int lsearch(int[],int,int);
int lsearch(int arr[10],int n,int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            return i;
            break;
        }
    }
    if(i>=n)
    {
        return -1;
    }
}
int main()
{
 int i,n,a[100],key,index;
 printf("\n  enter size of array");
 scanf("%d",&n);
 printf("\n enter %d elemants",n);
 for(i=0;i<n;i++)
 {
    scanf("%d",&a[i]);
 }


 printf("\n enter the element to search");
 scanf("%d",&key);

  index=lsearch(a,n,key);
   
    if(index>0)
    {
        printf("\n element found at position %d",index+1);
        
    }
    else
    {
        printf("\n element not found");
    }
    return 0;
}
