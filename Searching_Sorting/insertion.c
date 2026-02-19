#include<stdio.h>
void ins(int[],int );
void ins(int a[10],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
       temp=a[i];
       for(j=i-1;j>=0;j--)
       {
        if(a[j]>temp)
        {
            a[j+1]=a[j];

        }
        else
        {
            break;
        }
       }
    a[j+1]=temp;
    }
}
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
    ins(arr,n);
    printf("\nArray After Sorting");
    for(i=0;i<n;i++)
    {
       printf("%d\t",arr[i]);
    }
} 
