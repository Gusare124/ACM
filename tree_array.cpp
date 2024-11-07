#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define mod (ll)(1e9+7)
using namespace std;
/*
    数状数组
    1.单点修改(logn)
    2.区间求和(logn)
    
*/
#define lowbit(x) (x&(-x))
ll tree[N];
ll upperbound=N-1;
void update(ll start,ll add){
    for(ll pos=start;pos<=upperbound;pos+=lowbit(pos)){
        tree[pos]+=add;
        // 或者tree[pos]=(tree[pos]+add)%mod;
    }
}
ll query(ll up){
    ll ans=0;
    for(ll pos=up;pos;pos-=lowbit(pos)){
        ans+=tree[pos];
        // 或者 ans=(ans+tree[pos])%mod
    }
    return ans;
}
