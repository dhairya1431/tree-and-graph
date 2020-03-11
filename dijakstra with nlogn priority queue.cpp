#include<bits/stdc++.h>
using namespace std;
#define ll int
#define pb push_back
#define mp make_pair
#define ipair pair<ll,ll>
ll a[10]={0};

void dij(ll src,vector<pair<ll,ll>> graph[])
{
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    
    ll dis[10];
    for(ll i=0;i<10;i++)
    {
        dis[i]=INT_MAX;
        //cout<<i<< " "<<dis[i]<<endl;
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
    
    for(ll i=0;i<5;i++)
    {
        cout<<i<< " "<<dis[i]<<endl;
    }
}
int main()
{
    ll n;cin>>n;
    vector<pair<ll,ll>> graph[n];
    
    for(ll i=0;i<=5;i++)
    {
        ll u,v,w;cin>>u>>v>>w;
        graph[u].pb(mp(v,w));
        graph[v].pb(mp(u,w));
    

    dij(0,graph);
}
