#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define debug(x) cerr<<#x<<':'<<x<<'\n';
using namespace std;
/*
  差分约束：求出若干 xi-xj<=k 的一组解
  建立超级源点，到各个点连边，长度均为0，j到i连k的边
  将原约束转化为 dis[xi]<=dis[xj]+k 的最短路问题
  在这张图上跑spfa（因为k可以是负数）有负环则无解 没有负环则dis[xi]就是xi的一组解
*/
const int MAXN=5005;
struct edge {
  int v, w;
}temp;

vector<edge> e[MAXN];
ll dis[MAXN], cnt[MAXN], vis[MAXN];
queue<int> q;
int n,m;

bool spfa(ll st){
	memset(dis,0x3f,sizeof(dis));
	q.push(st);
	dis[st]=0,vis[st]=1;

	// for(ll i=0;i<=n;i++){
	// 	cerr<<"dis "<<i<<':'<<dis[i]<<'\n';
	// }

	while(!q.empty()){
		ll u=q.front();
		q.pop();
		vis[u]=0;
		
		for(ll i=0;i<e[u].size();i++){
			ll v=e[u][i].v;
			ll w=e[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				cnt[v]=cnt[u]+1;

				if(cnt[v]>n) return false;
				if(!vis[v]) q.push(v),vis[v]=1;
			}
		}
	}
	
	return true;
}
void solve(){
	cin>>n>>m;
	//建图
	for(ll i=1,u,v,c;i<=m;i++){
		cin>>u>>v>>c;
		temp.v=u,temp.w=c;
		e[v].push_back(temp);
	}

	//超级源点连边
	temp.w=0;
	for(ll i=1;i<=n;i++){
		temp.v=i;
		e[0].push_back(temp);
	}

	bool flag=spfa(0);
	if(!flag){
		cout<<"NO\n";
	} else {
		for(ll i=1;i<=n;i++){
			cout<<dis[i]<<' ';
		}
		cout<<'\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	ll T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
