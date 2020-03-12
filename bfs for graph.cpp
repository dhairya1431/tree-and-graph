#include<bits/stdc++.h>
using namespace std;
vector<int> g[200000+1];
int vis[200000+1]={0};

void bfs(int node)
{
    std::queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        for(int child : g[node])
        {
           
            if(vis[child]==0)
            {
                vis[child]=1;
                q.push(child);
            }
        }
    }
}
int main()
{
    int n,m;cin>>n>>m;
    int x,y;
    
    while(m--) cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
    
    int maxnode,maxde=0;
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()>maxde)
        {
            maxde=g[i].size();
            maxnode=i;
        }
    }
    //cout<<maxnode<<endl;
    bfs(maxnode);
}
