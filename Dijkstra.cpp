#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct edge{
    ll v; //指向的点v
    ll w; //边权w
    bool operator>(const edge& o)const{
        return w>o.w;
    }
}temp;
const ll N=10005;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
ll dis[N];
bool vis[N];
vector<edge> e[N];

void dijkstra(ll st);
void init();

void init(){
    for(ll i=1;i<=n;i++){
        dis[i]=inf;
    }
}
void dijkstra(ll st){
    //需要将dis全部设置为inf
    init();
    dis[st]=0;
    priority_queue<edge,vector<edge>,greater<edge> > q;
    temp.v=st,temp.w=0LL;
    q.push(temp);
    while(!q.empty()){
        ll u=q.top().v;
        q.pop();

        if(vis[u]) continue;
        vis[u]=true;
        for(auto ed:e[u]){
            ll v=ed.v;
            ll w=ed.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    temp.v=v,temp.w=dis[v];
                    q.push(temp);
                }
            }
        }
    }
}