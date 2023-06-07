#include<iostream>
using namespace std;

  class stack
{
   int top;
   int A[10];
   public:
   stack()
   {
      top=-1;
    }
    
   int empty()
   {
      if (top ==-1)
         return 1;
      else 
         return 0;
    } 
    
    int full()
    {
       if (top>=A[10])
         return 1;
       else
         return 0;
     }
    void push(int e1)
    {
      
      A[++top]= e1;
      
     }
     int pop()
     {
       int s=A[top];
       top--;
       return s;
      
       }
  };
  

   
  
int main()
{

   int n, e;
   int e1,e2;
   int G[10][10];
   int visited[10];

   cout<<"Enter number of nodes"<<endl;
   cin>>n;
   for(int i=0;i<n;i++) //initialize all nodes as 0 in visited array
   {
   visited[i]=0;
   }
      
   cout<<"Enter the number of edges"<<endl;
   cin>>e;
   
   for(int i=0;i<n;i++)
      {
         for(int j=0;j<n;j++)
         {
            G[i][j]=0;
         }
         
      }
   
      
   for(int i=0;i<e;i++)
      {
            cout<<"Enter edge (e1,e2)"<<endl;
            cin>>e1>>e2;
            G[e1][e2]=1;
            G[e2][e1]=1;
      }
      
      
   for(int a=0;a<n;a++)
  {
      for(int b=0;b<n;b++)
      {
         cout<<G[a][b];
       }
       cout<<endl;
   }
   
   
   stack st;
   //st.push(e1);
   //void DFS()
   //{
      cout<<"please enter starting vertex";
      cin>>e1;
         st.push(e1);
     
   
      while(!st.empty())
      {
         int v;
         v=st.pop();
         if(visited[v]==0)
         {
            visited[v]=1;
            cout<<v<<" ";
         }
      
      
      for(int j=n-1;j>=0;j--)
         {
            if (G[v][j]==1 && visited[j]==0) //if edge is present ie 1 and not visited ie 0
            {
               st.push(j);
            }
         }
     }
            
      
   
   return 0;
}
 

