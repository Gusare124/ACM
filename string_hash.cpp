#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    1. 仅小写，大写得稍微修改一下字母到数字的映射
    2. 左->右，高位->低位(base^len到base^1)
    3. 传入函数的s起始位置为0
*/
const ll base=31;
const ll mod=1e9+7;
ll hsh[200005];

ll qpow(ll a,ll x); //快速幂
ll hsh_single(string s); //单个字符串求哈希值
void hsh_pre(string s); //构建哈希前缀和
ll hsh_sub(ll l,ll r); //求[l,r]子串的哈希值

//求单个字符串的哈希值
const ll base=31;
ll hsh_single(string s){
    ll ans=0;
    for(char& c:s){
        ans=(ans+c-'a'+1)%mod;
        ans=ans*base%mod;
    }
    return ans;
}

//构建字符串哈希前缀和
void hsh_pre(string s){
    ll n=s.size();
    s=' '+s;
    for(ll i=1;i<=n;i++){
        hsh[i]+=(hsh[i-1]*base%mod+(s[i]-'a')*base%mod)%mod;
    }
}

//对字符串求子串哈希
ll hsh_sub(ll l,ll r){
    return (Hash[r]-Hash[l-1]*qpow(base,r-l+1)%mod+mod)%mod; //+mod的原因是防止减出来是负数
}

//快速幂
ll qpow(ll a,ll x){
    ll res=1;
    while(x){
        if(x&1) res=res*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return res;
}
