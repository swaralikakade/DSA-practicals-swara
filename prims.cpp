#include<iostream>
using namespace std;

class tree{
     int a[20][20],e1,e2,w,i,j,v,e,visited[20];
    public:
        void input();
        void display();
        void minimun();
};

void tree::input(){
    cout<<"\nEnter the number of nodes:";
    cin>>v;
    for(i=0;i<v;i++){
        visited[i]=0;
        for(j=0;j<v;j++){
            a[i][j]=999;
        }
    }

    cout<<"\nEnter the number of edges: ";
    cin>>e;

    for(i=0;i<e;i++){
        cout<<"\nEnter the end nodes of the edges : "<<endl;
        cin>>e1>>e2;
        cout<<"Enter the phone company charges for this connections: "<<endl;
        cin>>w;
        a[e1][e2]=a[e2][e1]=w;    
    }
}

void tree::display(){
    cout<<"\nAdjacency maatrix";
    for(i=0;i<v;i++){
        cout<<endl;
        for(j=0;j<v;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void tree::minimum()
{
    int p=0,q=0,total,min;
    visited[0]=1;
    for(int count=0; cout<(v-1);count++)
    {
        min=999;
        for(int i=0;i<v;i++){
            if(visited[i]==1){
                for(j=0;j<v;j++){
                    if(visited[j]!=1){
                        if(min>a[i][j]){
                            min=a[i][j]
                            p=i;
                            q=j;
                        }
                    }
                }
            }
        } 
        visited[p]=1;
        visited[q]=1;
        total+=min;
        cout<<"Minimum cost of connection is"<<(p)<<"->"<<(q)<<" will be "<<min<<endl;
    }
    cout<<"The minimum total cost of connections of all branches will be "<<total<<endl;
}


int main(){
    int ch;
    tree t;
    do
    {
        cout<<"\n----prims algorithm----";
        cout<<"\n----Menu----";
        cout<<"\n1.Input";
        cout<<"\n2.Display";
        cout<<"\n3.Minimum";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"\n----Input your values----";
                t.input();
                break;
            
            case 2: cout<<"\n----Display-----";
                t.display();
                break;
            
            case 3: cout<<"\n----Minimum-----"<<endl;
                t.minimun();
                break;
        }
        
    } while (ch!=4);
    
    return 0;
}









































































































