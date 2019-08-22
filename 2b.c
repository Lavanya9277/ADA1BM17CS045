#include<stdio.h>
void main()
{
  int arr[20],i,j,k,n,min_index,temp,p;
  printf("Enter the number of elements in array");
  scanf("%d",&n);
  printf("Enter the number k");
  scanf("%d",&k);
  printf("Enter the elements of array");
  for(i=0;i<n;i++)
   {
    scanf("%d",&arr[i]);
    }
 printf("The elements of array are:");
  for(i=0;i<n;i++)
  {
    printf("%d\n",arr[i]);
  }
for(i=0;i<n;i++)
{
  min_index=i;
   for(j=i+1;j<n-1;j++)
   {
     if(arr[min_index]>arr[j])
         min_index=j;
    }
   temp=arr[i];
   arr[i]=arr[min_index];
    arr[min_index]=temp;
   
}
 for(p=n-1;p>k-1;p--)
{
  printf("the k large numbers are :");
 printf("%d\n",arr[p]);
}
}
/*Enter the number of elements in array 6
  Enter the number k 3
  Enter the elements of array 7 10 3 4 20 15
  the elemennts of array are:7
  10
  3
  4 
  20
  15
  the kth smallest element is 7 */
  
