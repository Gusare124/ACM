#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll N=50;
/*
    combination_mod()
    模mod意义下的组合数，原理是用A算出来
    C[n][m]=n!/(n-m)!/m! 预处理阶乘及逆元
    A[n][m]=n!/(n-m)!
*/
ll A[N],inv[N]; //阶乘 逆元前缀积

ll qpow(ll x,ll y);
void init();
ll combination_mod(ll n,ll m);

ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}

void init(){
    A[1]=1;
    inv[1]=1;
    for(ll i=2;i<N;i++){
        A[i]=A[i-1]*i%mod;
        inv[i]=inv[i-1]*qpow(i,mod-2)%mod;
    }
}
ll combination_mod(ll n,ll m){
    init();
    if(n<0 || m<0 || n<m) return 1;
    else return A[n]*inv[m]%mod*inv[n-m]%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    cout<<combination_mod(5,2)<<'\n';
    return 0;
}