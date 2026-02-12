#include<stdio.h>
void bubble(int arr[],int);
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
    bubble(arr,n);
    printf("\nArray After Sorting");
    for(i=0;i<n;i++)
    {
       printf("%d\t",arr[i]);
    }
}
void bubble(int arr[10],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}