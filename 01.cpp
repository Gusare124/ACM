#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    01背包板子
    1. dp[i]:(实·际·用·了)i单位背包的最大价值
    2. v[i]:第i个物品的价值 w[i]:第i个物品的体积
*/
ll n,m;
ll v[10005],w[10005],dp[20005];

int main(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    //dp[0]=0 dp数组初始化省略了
    for(ll i=1;i<=n;i++){
        for(ll j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    ll Max=0;
    for(ll i=0;i<=m;i++){
        Max=max(dp[i],Max);
    }
    cout<<Max<<'\n'; //最大体积为m的最大价值(不一定全装满)
    cout<<dp[m]<<'\n'; //实际用了m体积的最大价值(已经装满)
    return 0;
}