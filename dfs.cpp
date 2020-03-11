#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll int
 ll visit[10]={0};
 
void dfs(ll node,vector<int> g[])
{
       if(visit[node]==0)
       {
           cout<<node<<" ";
           visit[node]=1;
           for(int i=0;i<g[node].size();i++)
           {
               if(visit[g[node][i]]==0)
               dfs(g[node][i],g);
           }
       }
    
}
int main()
{
    int n;cin>>n;
   
    vector<int> g[n];
    // g[1].push_back(0);
    // g[0].push_back(1);
    for(ll i=1;i<=3;i++)
    {
        ll u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i=1;i<=5;i++)
    {
        if(visit[i]==0)
        dfs(i,g);
    }
}
