#include<bits/stdc++.h>
#define ll long long
#define debug(x) cerr<<#x<<'='<<x<<'\n';
#define inf 0x3f3f3f3f3f3f3f3f
#define N 100005
#define MAX 20  //不小于lg2[n]
using namespace std;
/*
    st表:
        0. st[i][j]=[i,i+2^j-1]的最值
        1. st[i][j]=min/max(st[i][j-1],st[i+(1<<j-1)][j-1])
           即[i,i+2^j-1]=min/max([i,i+2^(j-1)-1],[i+2^(j-1),(i+2^(j-1))+(2^(j-1)-1)])
        1. 构建 O(nlogn)
        2. 查询 O(1)
        3. 不可修改
*/

ll st[N][MAX],lg2[N];
ll n,m,l,r;

void solve();

void solve(){
    cin>>n>>m;

    //预处理lg2[i]=[log2[i]];
    for(ll i=2;i<=n;i++){
        lg2[i]=lg2[i/2]+1;
    }

    //st表初始化 st[i][0]=[i,i+2^0-1]=[i,i];
    for(ll i=1;i<=n;i++){
        cin>>st[i][0];
    }

    //构建st表
    for(ll j=1;j<MAX;j++){
        for(ll i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
        }
    }

    //回答查询
    for(ll i=1;i<=m;i++){
        cin>>l>>r;
        ll s=r-l+1;
        cout<<max(st[l][lg2[s]],st[r-(1<<lg2[s])+1][lg2[s]])<<'\n'; //r那个要+1 !!!
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}