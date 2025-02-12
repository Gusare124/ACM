#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;

    vector<bool> not_prime(n+1,false);
    vector<ll> vec;

    not_prime[1]=true;
    for(ll i=2;i<=n;i++){
        if(!not_prime[i]){
            vec.push_back(i);
            for(ll j=i*i;j<=n;j+=i){
                not_prime[j]=true;
            }
        }
    }

    return 0;
}