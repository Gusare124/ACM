#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[100][100]; //f[i][j]:从i到j的最短距离
void floyd(ll n){
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
