#include<iostream>
using namespace std;
int main()
{
  int n,a[10][10],indeg[10],flag[10],count=0;
  cout<<"enter the no of vertices:";
  cin>>n;
  cout<<"enter the matrix";
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<n;j++)
   {
     cin>>a[i][j];
   }
  }
  for(int i=0;i<n;i++)
  {
    indeg[i]=0;
    flag[i]=0;
   }
 for( int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
    if(a[i][j]==1)
      indeg[j]++;
   }
  }
  cout<<"topological order";
  while(count<n)
  {
   for(int k=0;k<n;k++)
   {
     if((indeg[k]==0)&&(flag[k]==0))
     {
       cout<<k<<" ";
       flag[k]=1;
       count++;
      }
      for(int i=0;i<n;i++)
      {
       if(a[k][i]==1)
         indeg[i]--;
       }
     }
     
   }
   return 0;
 }    
               
    
  
