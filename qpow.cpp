#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod=1e9+7;
//用O(logn)求a^n

ll qpow(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1){
            ans=ans*a%mod;
        }
        n>>=1;
        a=a*a%mod;
    }
    return ans;
}
/*
逆元
inv(a)=qpow(a,mod-2)
*/
