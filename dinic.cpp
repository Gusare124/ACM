#include<bits/stdc++.h>
#define ll long long
const int M=10005;
const int N=10005;
using namespace std;
/*
    e[i]:第i条出边 v:下一个节点 c流量 ne下一条边
    表头h[i]:i点的第一条出边
    深度d[i]:存i点所在图层
    当前弧cur[i]:存i点的当前出边

    bfs() 从源点S出发，对点分层，找增广路
    dfs() 多路增广
    (1) 搜索顺序优化(分成限制搜索深度)
    (2) 当前弧优化(剪枝)
    (3) 剩余流量优化(剪枝)
    (4) 残枝优化(剪枝)

    dinic() 累加可行流
*/
struct edge{ ll v,c,ne; }e[M];
int h[N],idx=1,S,T,n,m; //点从2,3开始成对编号
int d[N],cur[N];

void add(int a,int b,int c);
bool bfs(int S);
ll dfs(int u,ll mf);
void solve();

void add(int a,int b,int c){
    ++idx;
    e[idx].v=b,e[idx].c=c,e[idx].ne=h[a];
    h[a]=idx;
}
bool bfs(int S){
    memset(d,0,sizeof(d));
    queue<int> q;
    q.push(S); d[S]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=h[u];i;i=e[i].ne){
            int v=e[i].v;
            if(d[v]==0 && e[i].c){ //该点未分层 且 剩余流量不为0
                d[v]=d[u]+1;
                q.push(v);
                if(v==T) return true;
            }
        }
    }
    return false;
}
ll dfs(int u,ll mf){
    if(u==T) return mf;
    ll sum=0;
    for(int i=cur[u];i;i=e[i].ne){
        cur[u]=i;
        int v=e[i].v;
        if(d[v]==d[u]+1 && e[i].c){
            ll f=dfs(v,min(mf,e[i].c));
            e[i].c-=f;
            e[i^1].c+=f;
            sum+=f;
            mf-=f;
            if(mf==0) break;
        }
    }
    if(sum==0) d[u]=0;
    return sum;
}
ll dinic(){
    ll flow=0;
    while(bfs(S)){
        memcpy(cur,h,sizeof(h)); //更新残留网 cur和h必须大小相同
        flow+=dfs(S,1e9);
    }
    return flow;
}
void solve(){
    cin>>n>>m>>S>>T;
    for(int i=1,u,v,c;i<=m;i++){
        cin>>u>>v>>c;
        add(u,v,c);
        add(v,u,0); //成对存储！
    }
    cout<<dinic()<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
