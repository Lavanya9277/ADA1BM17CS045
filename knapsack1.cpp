#include<iostream>
#include<cmath>
using namespace std;
void dpknapsack(int *wt,int *val,int n,int w)
{
 int i,j;
 int dp[n+1][w+1];
 for(i=0;i<=n;i++)
 {
   dp[i][0]=0;
 }
 for(j=1;j<=w;j++)
 {
   dp[0][j]=0;
 }
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=w;j++)
  {
    if(j-wt[i]>=0)
    {
      dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i]]);
     }
     else
        dp[i][j]=dp[i-1][j];
        
    }
  }
  for(i=0;i<=n;i++)
  {
    cout<<"\n";
    for(j=0;j<=w;j++)
    {
     cout<<dp[i][j]<<" ";
    }
   }  
    
  
  cout<<"\n MAximum value:"<<dp[n][w]<<endl;
  cout<<"Include items with weight:";
  i=n;
  j=w;
  int sum=0;
  while(i>0&&j>0)
  {
    if(dp[i-1][j]==dp[i][j])
       i--;
    else
       {
       if(dp[i][j]==dp[i-1][j-wt[i]]+val[i])
       {
         cout<<"wt:"<<wt[i]<<"val:"<<val[i]<<"\t";
         sum+=val[i];
         j=j-wt[i];
         i--;
       }
      }
   }
   if(sum==dp[n][w])
     cout<<endl;
   else
      cout<<"wt:"<<wt[i]<<"val:"<<val[i]<<"\n";
  }
  int main()
  {
   int *wt,*val,n,w;
   cout<<"enter knapsack capacity";
   cin>>w;
   cout<<"Enter number of items";
   cin>>n;
   wt=new int[n+1];
   val=new int[n+1];
   cout<<"enter weight and value";
   for(int i=1;i<=n;i++)
   {
    cin>>wt[i];
    cin>>val[i];
   }
   dpknapsack(wt,val,n,w);
   return 0;
  } 
    
                         
    
