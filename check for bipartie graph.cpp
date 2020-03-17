#include<bits/stdc++.h>
using namespace std;

vector<int> g[100];
int vis[100]={0};
int color[100]={0};

   
 queue<int> q; 
void bfs(int node)
{
    q.push(node);
    vis[node]=1;
    color[node]=2;
   while(!q.empty())
   {  
       int node=q.front();
       q.pop();
       
       for(int child : g[node])
       {
           if(!vis[child])
           {
              q.push(child);
              vis[child]=1;
              color[child]=2-color[node];
           }
           else if(vis[child] && color[child]==color[node])
           {
               cout<<child<<' '<<node<<endl;
               cout<<"\nNOt bipartie\n";
               return;
           }
       }
   }
   cout<<"\ngraph is bipartie\n";
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
}
