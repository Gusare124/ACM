#include<bits/stdc++.h>
#define ll long long
#define mod (ll)(1e9+7)
using namespace std;

/*
    1. 仅小写
    2. 高位到低位(base^len到base^1)
*/
const ll base=31;
ll hsh(string s){
    ll ans=0;
    for(char& c:s){
        ans=(ans+c-'a'+1)%mod;
        ans=ans*base%mod;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<hsh("ab")<<'\n';
    return 0;
}