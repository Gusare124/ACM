#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define N 500005

using namespace std;

ll n,m,s,a,b,id;
ll dfn[N],st[N][22],lg2[N];
vector<ll> e[N];

void dfs(ll x,ll fa);
ll query(ll x,ll y);
ll lca(ll u,ll v);

void dfs(ll x,ll fa){
    dfn[x]=++id;
    st[dfn[x]][0]=fa;

    for(ll j=0;j<e[x].size();j++){
        if(e[x][j]==fa){
            continue;
        }
        dfs(e[x][j],x);
    }
}

ll query(ll u,ll v){
    if(dfn[u]<dfn[v]){
        return u;
    } else {
        return v;
    }
}

ll lca(ll u,ll v){
    if(u==v){
        return u;
    }
    u=dfn[u];
    v=dfn[v];
    if(u>v){
        swap(u,v);
    }
    ll d=lg2[v-u];
    return query(st[u+1][d],st[v-(1LL<<d)+1][d]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m>>s;

    vector<vector<ll> > e(n+1);

    //建树
    for(ll i=1;i<=n-1;i++){
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    //构造lg2
    for(ll i=2;i<=n+1;i++){
        lg2[i]=lg2[i/2]+1;
    }


    dfs(s,s);

    for(ll i=1;i<=21;i++){
        for(ll j=1;j<=n-(1LL<<i)+1;j++){
            st[j][i]=query(st[j][i-1],st[j+(1LL<<(i-1))][i-1]);
        }
    }

    for(ll i=1;i<=m;i++){
        cin>>a>>b;
        cout<<lca(a,b)<<'\n';
    }

    return 0;
}