#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;

    vector<bool> vis(n+1,true);
    vector<ll> vec;

    for(ll i=2;i<=n;i++){
        if(vis[i]){
            vec.push_back(i);
        }
        for(ll j=0;i*vec[j]<=n;j++){
            vis[vec[j]*i]=false;
            if(i%vec[j]==0){
                break;
            }
        }
    }

    return 0;
}