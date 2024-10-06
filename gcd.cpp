#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<'\n';
    return 0;
}