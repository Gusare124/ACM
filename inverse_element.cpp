#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define debug(x) cerr<<#x<<':'<<x<<'\n';
using namespace std;
const ll mod=1e9+7;
ll inv[200001],pre[200001];

void ExPower(ll b,ll p,ll& a,ll& k);
void upd();
/*
	求逆元
	1. 模数任意：扩展欧几里得
	2. 模数为素数：
		（1）费马小定理 qpow(x,mod-2) 每次更新都是log(mod)
		（2）线性求逆元 
*/
void ExPower(ll b,ll p,ll& a,ll& k){ //b:要求逆元的数 p:模数 a:逆元 
	if(p==0){
		a=1,k=0;
		return ;
	}
	ExPower(p,b%p,k,a);
	k-=b/p*a;
	return ;
}
void upd(){
	pre[0]=1,pre[1]=1;
	inv[0]=1,inv[1]=1; //1要预设，不然inv[1]被inv[0]更新为0
	for(int i=2;i<=200000;i++) pre[i]=i;
	for(int i=2;i<=200000;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;

	//求前缀积
	for(int i=2;i<=200000;i++) pre[i]=pre[i]*pre[i-1]%mod;
	for(int i=2;i<=200000;i++) inv[i]=inv[i-1]*inv[i]%mod;
	
}
