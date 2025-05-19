#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define debug(x) cerr<<#x<<':'<<x<<'\n';
using namespace std;

const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
/*
	区间和线段数
	空间 tr[4*N]
	1. 区间查询 O(logn) 
	2. 区间修改 O(logn)
*/

struct info{
	int l,r;
	ll sum,add;
}tr[400005];
int n,m;
ll a[100005];


void build(int p,int l,int r); //建树
void pushup(int p); //子节点更新父节点
void pushdown(int p); //父节点更新子节点
void update(int p,int x,int y,ll k); //[x,y]区间加k
ll query(int p,int x,int y); //查询[x,y]之和
void solve();

void pushup(int p){
	tr[p].sum=tr[2*p].sum+tr[2*p+1].sum;
}
void build(int p,int l,int r){
	tr[p].l=l;
	tr[p].r=r;
	tr[p].sum=a[l];
	tr[p].add=0;

	if(l==r) return ;
	int m=(l+r)/2;
	build(2*p,l,m);
	build(2*p+1,m+1,r);
	pushup(p);
}
void update(int p,int x,int y,ll k){
	if(x<=tr[p].l && tr[p].r<=y){
		tr[p].sum+=(tr[p].r-tr[p].l+1)*k;
		tr[p].add+=k;
		return ;
	}
	pushdown(p);

	int m=(tr[p].l+tr[p].r)/2;
	if(x<=m) update(2*p,x,y,k);
	if(y>m) update(2*p+1,x,y,k);

	pushup(p);
}
void pushdown(int p){
	if(tr[p].add){
		//左子树更新sum和add
		tr[2*p].sum+=tr[p].add*(tr[2*p].r-tr[2*p].l+1);
		tr[2*p].add+=tr[p].add;

		//右子树更新sum和add
		tr[2*p+1].sum+=tr[p].add*(tr[2*p+1].r-tr[2*p+1].l+1);
		tr[2*p+1].add+=tr[p].add;

		tr[p].add=0;
	}
}
ll query(int p,int x,int y){
	if(x<=tr[p].l && tr[p].r<=y){
		return tr[p].sum;
	}
	pushdown(p);
	int m=(tr[p].l+tr[p].r)/2;
	ll sum=0;
	if(x<=m) sum+=query(2*p,x,y);
	if(y>m) sum+=query(2*p+1,x,y);
	return sum;
}
