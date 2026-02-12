#include<stdio.h>
int b_search(int[],int,int);
int b_search(int arr[10],int n,int k)
{
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]<k)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(low>=high)
    {
        return -1;
    }
    return 0;
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

  index=b_search(a,n,key);
   
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
