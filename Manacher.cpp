#include<bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;
//N:字符串长度上限+5
char vec[N<<1];
ll Max;
ll p[N<<1];
void manacher(string& s){
    s=' '+s;
    ll len=s.size();

    //初始化char数组(插入非字符集)
    vec[0]='*';
    for(ll i=1;i<=len;i++){
        vec[i*2]=s[i];
        vec[i*2-1]='#';
    }
    vec[2*len+1]='#';
    vec[2*len+2]='$';

    //Manacher
    for(ll i=1,c=0,r=0;i<=2*len+1;i++){
        if(i<=r){ //未超过最右侧,由对称性得最小值
            p[i]=min(r-i,p[2*c-i]);
        }
        while(vec[i-p[i]-1]==vec[i+p[i]+1]){ //中心扩展
            p[i]++;
        }
        //Max=max(Max,p[i]);
        if(i+p[i]>r){ //更新右端
            r=i+p[i];
            c=i;
        }
    }
    // Max:最大回文串的长度
}