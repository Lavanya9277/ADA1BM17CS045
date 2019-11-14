#include<iostream>
#include<cmath>
using namespace std;
int a[10][10];
void  floyd(int a[10][10],int n)
{
 int i,j,k;
 for ( k=1;k<=n;k++)
 {
   for( i=1;i<=n;i++)
    {
     for( j=1;j<=n;j++)
     {
       if((a[i][k]*a[k][j] != 0) && (i!=j))
       {
        if((a[i][k]+a[k][j]<a[i][j]) || (a[i][j]==0))
        {
         a[i][j]=a[i][k]+a[k][j];
         }
      }
    }
  }
}
for( i=1;i<=n;i++)
{
  for( j=1;j<=n;j++)
 {
  cout<<a[i][j]<<"\t";
  
  }
 cout<<"\n";
 }
}


 int main()
{ 
 int n;
 cout<<"enter the number of vertices";
 cin>>n;
 cout<<"Enter the adjacency matrix";
 for(int i=1;i<=n;i++)
 {
   for(int j=1;j<=n;j++)
   {
     cin>>a[i][j];
   }
 }
 floyd(a,n);
}


