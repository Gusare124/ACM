#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    01背包方案数板子
    1. dp[i]:(实·际·填·满·了)i单位背包的方案数
    2. w[i]:第i个物品的体积
*/
ll n,m;
ll w[10005],dp[20005];

int main(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>w[i];
    }

    dp[0]=1; //背包体积为0,方案数为1,即什么都不放

    for(ll i=1;i<=n;i++){
        for(ll j=m;j>=w[i];j--){
            dp[j]+=dp[j-w[i]];
        }
    }

    cout<<dp[m]<<'\n'; //实际用了m体积的方案数(已经装满)
    return 0;
}