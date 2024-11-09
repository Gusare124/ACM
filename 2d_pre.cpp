#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    二维前缀和板子 （n*m的矩阵）

    1.构建二维前缀和
    2.求(a,b)-(x,y)的矩阵的前缀和(a<=x && b<=y)
*/
ll n,m;
ll a[105][105];
ll pre[105][105];

void init();

void init(){
    for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
		}
	}
}
ll result(ll a,ll b,ll x,ll y){
    //(a,b)左上 (x,y)右下
    return pre[x][y]-pre[a-1][y]-pre[x][b-1]+pre[a-1][b-1];
}