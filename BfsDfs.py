#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void BFS(int s,int adj[10][10],int vis[10],int n)
{
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        cout<<i<<"-->";
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]==1 && vis[j]!=1)
            {
                q.push(j);
                vis[j]=1;
            }
        }
    }
    cout<<"NULL"<<endl;
}

void DFS(int s,int adj[10][10],int vis[10],int n)
{
    stack<int> stk;
    stk.push(s);
    vis[s]=1;
    while(!stk.empty())
    {
        int i=stk.top();
        stk.pop();
        cout<<i<<"-->";
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]==1 && vis[j]!=1)
            {
                stk.push(j);
                vis[j]=1;
            }
        }
    }
    cout<<"NULL"<<endl;
}

int main()
{
    int n;
    cout<<"Enter the Number of Nodes in the Graph : ";
    cin>>n;
    int adj[10][10]={0},vis[10]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                break;
            cout<<"Do you want Edge between "<<i<<" & "<<j<<" (Y/N) ? :";
            char ch;
            cin>>ch;
            if(ch=='y' || ch=='Y'){
                adj[i][j]=adj[j][i]=1;
            }
        }
    }
    cout<<"\nThe BFS on the given graph is : "<<endl;
    BFS(0,adj,vis,n);

    for(int i=0;i<n;i++)
        vis[i]=0;

    cout<<"\nThe DFS on the given graph is : "<<endl;
    DFS(0,adj,vis,n);
}
