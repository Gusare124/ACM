#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    exgcd返回值:
    1. gcd(a,b)
    2. 一组(x,y)特解
*/
ll exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll x2=x,y2=y; //(x2,y2)
    x=y2;
    y=x2-(a/b)*y2;
    return d;
}
