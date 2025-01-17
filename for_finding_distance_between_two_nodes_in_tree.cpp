/* for finding shortest distance between two nodes used specially for queries problems */


#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll int

ll n;
const int  maxN=log2(15)+1;
 ll visit[20]={0};
 ll parent[20][4]={0};
 ll lev[20]={0};
void dfs(ll node,ll level,vector<int> g[])
{
       if(visit[node]==0)
       {
           lev[node]=level;
           cout<<node<<" ";
           visit[node]=1;
           for(int i=0;i<g[node].size();i++)
           {
                
               if(visit[g[node][i]]==0)
               {
                  parent[g[node][i]][0]=node;
                  
                   dfs(g[node][i],level+1,g);
               }
           }
       }
    
}
void init(int n)
{
    for(int j=1;j<maxN;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(parent[i][j-1]!=0)
            {
                int par=parent[i][j-1];
                parent[i][j]=parent[par][j-1];  
            }
        }
    }
    
   /* for(int i=1;i<=n;i++)
    {
        for(int j=0;j<maxN;j++)
        cout<<parent[i][j]<<" ";
        cout<<endl;
    }*/
}
int lca(int x,int y)
{
    
    int temp=abs(lev[x]-lev[y]);
    
    if(lev[y]>lev[x])
    y=x+y-(x=y);
    
   
        while(temp>0)
        {
            int i=log2(temp);
            x=parent[x][i];
            temp-=1<<i;
        }
    
    
    if(x==y) return x;
    
    for(int i=maxN-1;i>=0;i--)
    {
        if(parent[x][i]!=0 && (parent[x][i]!=parent[y][i]))
        x=parent[x][i],y=parent[y][i];
    }
    return parent[x][0];
}
int main()
{
    cin>>n;
    vector<int> g[n+1];
    
    for(ll i=1;i<=(n-1);i++)
    {
        ll u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        
    }
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        dfs(i,0,g);
    }
    cout<<endl;
    init(n);
    // for(int i=1;i<=n;i++)
    // cout<<i<<" "<<parent[i][0]<<endl;
    
    
    int x,y;cin>>x>>y;
    //cout<<lca(x,y)<<endl; // For finding LCA of two nodes
    cout<<lev[x]+lev[y] - 2*lev[lca(x,y)]<<endl; //for finding shortest distance between two nodes used specially for queries problems
}
