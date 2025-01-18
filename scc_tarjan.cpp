#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=10005;
vector<ll> e[N]; //存图
ll dfn[N],low[N],tot; //dfn序,lowvalue,tot为dfn计数器
bool instack[N]; //instack是否在栈内
ll stk[N],top; //stk数组模拟栈,top为栈内元素个数计数器
ll scc[N],sz[N],cnt; 
//每个点的scc编号（记录为第几个强连通分量）,以及sz强连通分量大小计数,cnt强连通分量个数计数器
ll n,m; //n点的个数，m边个数
bool vis[N];

void tarjan(ll x);

void tarjan(ll x){
	dfn[x]=low[x]=++tot;
	stk[++top]=x,instack[x]=true;
	for(ll& y:e[x]){
		if(!dfn[y]){ //未遍历过
			tarjan(y);
			low[x]=min(low[x],low[y]);
		} else if(instack[y]){ //已遍历过 且 在栈中
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x]){ //找到强连通分量
		ll y;
		++cnt;
		do{
			y=stk[top--]; //分量内点y
			instack[y]=false; //y出栈
			scc[y]=cnt; //y是第cnt个强连通分量
			++sz[cnt]; //给第cnt个强连通分量大小自增
		}while(y!=x);
	}
}