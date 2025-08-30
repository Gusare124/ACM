#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define debug(x) cerr<<#x<<':'<<x<<'\n';
using namespace std;
/*
	求凸包andrew
*/
struct point{
	int x,y;
	bool operator<(const point& o)const{
		return (x==o.x?y<o.y:x<o.x);
	}
}p[50001],s[100001];
int n,top;

double cross(point a,point b,point c);
void andrew();
void solve();

double cross(point a,point b,point c){
	return ((c.y-a.y)*(b.x-a.x)-(c.x-a.x)*(b.y-a.y));
}
void andrew(){
	sort(p+1,p+n+1); //x从小到大，y从小到大

	for(int i=1;i<=n;i++){ //上凸包
		while(top>1 && cross(s[top-1],s[top],p[i])>=0) --top;
		s[++top]=p[i];
	}
	int t=top;
	for(int i=n-1;i>=1;i--){ //下凸包
		while(top>t && cross(s[top-1],s[top],p[i])>=0) --top;
		s[++top]=p[i];
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
	}
	andrew();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}