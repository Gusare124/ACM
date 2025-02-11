#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=50;
const ll mod=1e9+7;

void combination();


/*
    1.combination()
    C[i][j] i下j上
    不取模可能会爆longlong
*/
ll C[N][N];
void combination(){
    for(ll i=0;i<N;i++){
        C[i][0]=1;
        for(ll j=1;j<N-1;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
        C[i][i]=1;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    combination();
    cout<<C[5][2]<<'\n';
    return 0;
}
