#include<bits/stdc++.h>
using namespace std;
#define ll int
#define pb push_back
#define mp make_pair
#define ipair pair<ll,ll>
ll a[10]={0};
vector<pair<ll,ll>> graph[100];


void dij(ll src,ll n)
{
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    
    ll dis[n+10];
    for(ll i=1;i<=n;i++)
    {
        dis[i]=INT_MAX;
       // cout<<i<< " "<<dis[i]<<endl;
    }
    pq.push(mp(0,src));
    dis[src]=0;
    
    while(!pq.empty())
    {
        ll u=pq.top().second;
        
        pq.pop();
        for(ll i=0;i<graph[u].size();i++)
        {
            ll v=graph[u][i].first;
            ll weight=graph[u][i].second;
            
           // cout<<u<<" "<<v<<" "<<weight<<endl;
            
            if(dis[v]> dis[u]+weight)
           {
                dis[v]=dis[u]+weight;
                pq.push(mp(dis[v],v));
           }
        }
    }
    
    for(ll i=1;i<=n;i++)
    {
        cout<<i<< " "<<dis[i]<<endl;
    }
}
int main()
{
    ll n;cin>>n;
    ll m;cin>>m;
    
    
    while(m--)
    {
        ll u,v,w;cin>>u>>v>>w;
        graph[u].pb(mp(v,w));
        graph[v].pb(mp(u,w));
    }

    dij(1,n);
}
