#include<iostream>
using namespace std;
#define unassigned 0
#define N 4
#define sqn 2
int row,col;
bool FindUnassignedLocation(int grid[N][N],int &row,int &col);
bool isSafe(int grid[N][N],int row,int col,int num);
bool UsedInRow(int grid[N][N],int row,int num);
bool UsedInCol(int grid[N][N],int col,int num);
bool UsedInBox(int grid[N][N],int boxStartRow,int boxStartCol,int num);



bool FindUnassignedLocation(int grid[N][N],int &row,int &col)
{
  for(row=0;row<N;row++)
    for(col=0;col<N;col++)
      if(grid[row][col]==unassigned)
        return true;
  return false;
}

bool isSafe(int grid[N][N],int row,int col,int num)
{
   return !UsedInRow(grid,row,num)&&!UsedInCol(grid,col,num)&&!UsedInBox(grid,row-row%sqn,col-col%sqn,num);
}
 

bool UsedInRow(int grid[N][N],int row,int num)
{
  for(int col=0;col<N;col++)
   if(grid[row][col]==num)
     return true;

  return false;
}
 
bool UsedInCol(int grid[N][N],int col,int num)
{
  for(int row=0;row<N;row++)
    if(grid[row][col]==num)
      return true;
  return false;
}
bool UsedInBox(int grid[N][N],int boxStartRow,int boxStartCol,int num)
{
  for(int row=0;row<sqn;row++)
    for(int col=0;col<sqn;col++)
     if(grid[row+boxStartRow][col+boxStartCol]==num)
       return true;
 return false;
}

bool SolveSudoku(int grid[N][N])
{
  
  if(!FindUnassignedLocation(grid,row,col))
    return true;
  for(int num=1;num<=N;num++)
  {
    if(isSafe(grid,row,col,num))
    {
      grid[row][col]=num;
     if(SolveSudoku(grid))
      return true;
     grid[row][col]=unassigned;
    }
   }
   return false;
}

void printGrid(int grid[N][N])  
{  
    for (int row = 0; row < N; row++)  
    {  
    for (int col = 0; col < N; col++)  
         cout << grid[row][col] << " ";  
        cout << endl; 
    }  
}  


int main()  
{  
int grid[N][N]={0};
cout<<"enter the data in matrix form \n";
for(int i=0;i<N;i++)
{
 for(int j=0;j<N;j++)
 {
  cin>>grid[i][j];
 }
} 
if (SolveSudoku(grid) == true)  
        printGrid(grid);  
    else
        cout << "No solution exists";  
  
  return 0; 
} 

  

