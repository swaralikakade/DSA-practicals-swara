#include<iostream>
using namespace std;

class queue{
	public:
		int f,r;
		int arr[10];
		queue()
		{
			f=r=-1;
		}	 
		void enqueue(int data) 
		{
			if(f==-1)
				f++;
			r++;
			arr[r]=data;
		}
		int dequeue()
		{
			int x;
			x=arr[f];
			f++;
			return x;
		}
		int isEmpty()
		{
			if((f==-1)||f>r)
				return 0;
                        else			
                                return 1;
		}
};
              
class node
{
    public:
        int data;
        node *next;
        
        void insert(int u,int v,node *G[])
        {
            node *p=new node();
            p->data=v;
            p->next=NULL;
            if(G[u]==NULL)
            {
                G[u]=p;
            }
            else
            {
                node *q;
                for(q=G[u];q->next!=NULL;q=q->next);
                q->next=p;
            }
        }
};



int main()
{
    int que[10],n,i,e,u,v,s,v1;
    int visited[10];
    node *G[10],*p;
    queue q;
    node n1;

    cout<<"\nEnter number of nodes : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        G[i]=NULL;
    }
    cout<<"\nEnter number of edges : ";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<"\nEnter edge in pair : ";
        cin>>u>>v;
        n1.insert(u,v,G);
        n1.insert(v,u,G);
    }
  
    
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    cout<<"\nEnter the starting vertex : ";
    cin>>s;
    cout<<"\n\nBFS TRAVERSAL :\n";
    cout<<"\t"<<s;
    visited[s]=1;
    
    q.enqueue(s);
    while(q.isEmpty() != 0)
    {
        v1=q.dequeue();
        
        for(p=G[v1];p!=NULL;p=p->next)
        {
            if(visited[p->data]==0)
            {
                q.enqueue(p->data); 
                visited[p->data]=1;
        		cout<<"\t"<<p->data;
            }
        }
    } 
    return 0;
}
