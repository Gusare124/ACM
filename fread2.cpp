#include<bits/stdc++.h>
using namespace std;

char buf[1<<21],*p1=buf,*p2=buf;

inline char gc(){
    if(p1 == p2) p2=(p1=buf)+fread(buf,1,1<<21,stdin);
    return *(p1++);
}

inline int read(){
    int s=0,w=1;
    char ch=gc();
    while(ch<'0' || ch>'9'){
        if(ch=='-') w=-1;
        ch=gc();
    }
    while('0'<=ch && ch<='9'){
        s=(s<<1)+(s<<3)+(ch^48);
        ch=gc();
    }
    return s*w;
}