#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
/*
    并查集板子
*/
ll sz[N];  //sz[i]:i所在集合的大小
ll fa[N]; //fa[i]:i的父节点
ll n;

ll find(ll x);
bool query(ll x,ll y);
void init();
void unite(ll x,ll y);

//集合初始化
void init(){
    for(ll i=1;i<=n;i++){
        sz[i]=1;
        fa[i]=i;
    }
}

//将x和y所在集合合并
void unite(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x==y){ //x和y已在同一集合
        return ;
    }
    if(sz[x]>sz[y]){
        fa[y]=x;
        sz[x]+=sz[y];
    } else{
        fa[x]=y;
        sz[y]+=sz[x];
    }
}

//更新并返回x的父节点
ll find(ll x){
    return (fa[x]==x?x:(fa[x]=find(fa[x]))); //第三目的括号别忘
}

//查询x和y是否在同一集合
bool query(ll x,ll y){
    return (find(x)==find(y));
}
