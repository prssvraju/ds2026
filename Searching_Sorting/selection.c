#include<stdio.h>
void selection_sort(int[],int);
int main()
{
    int arr[10],n,i;
    printf("\nenter the size less than 10");
    scanf("%d",&n);
    printf("\nenter values in array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nArray befor Sorting");
    for(i=0;i<n;i++)
    {
       printf("%d\t",arr[i]);
    }
   selection_sort(arr,n); 
    printf("\nArray After Sorting");
    for(i=0;i<n;i++)
    {
       printf("%d\t",arr[i]);
    }
} 
void selection_sort(int a[10],int n)
{
    int i,j,min,temp;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}