#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
/*
    哈希表板子
    1. Hash 单哈希
    2. DoubleHash 双哈希

    大mod/大base见模版

    小mod: 1e9+7, 1e9+9
    小base: 131,13331,29
*/

struct Hash{
    ull base=1000000033ULL,mod=212370440130137957ULL;
    vector<ull> pow,ha; //pow: base的i次方

    Hash(){}
    Hash(string& s){//注意这里是引用,下面的‘ ’+s会改变外部的s
        int n=s.size();
        s=' '+s;

        pow.resize(n+1,0);
        ha.resize(n+1,0);
        pow[0]=1;
        
        for(int i=1;i<=n;i++){
            pow[i]=(pow[i-1]*base)%mod;
            ha[i]=(ha[i-1]*base%mod+s[i])%mod;
        }
    }

    ull get(int l,int r){
        return (ha[r]-ha[l-1]*pow[r-l+1]%mod+mod)%mod;
    }

    ull link(int l1,int r1,int l2,int r2){ //s[l1,r1][l2,r2]拼接后的哈希值(拼好string)
        return (get(l1,r1)*pow[r2-l2+1]%mod+get(l2,r2))%mod;
    }

    bool same(int l1,int r1,int l2,int r2){
        return (get(l1,r1)==get(l2,r2));
    }
};

struct DoubleHash{
    ull mod1=212370440130137957ULL,mod2=1000000000000000003ULL;
    ull base1=1000000033ULL,base2=131ULL;
    vector<ull> pow1,pow2,ha1,ha2;
    vector<ull> rha1,rha2;
    int n;

    DoubleHash(){}
    DoubleHash(string& s){
        init(s);
    }

    void init(string& s){
        n=s.size();
        s=' '+s;

        pow1.resize(n+1,0),pow2.resize(n+1,0);
        ha1.resize(n+1,0),ha2.resize(n+1,0);
        rha1.resize(n+1,0),rha2.resize(n+1,0);
        pow1[0]=1,pow2[0]=1;

        for(int i=1;i<=n;i++){
            pow1[i]=pow1[i-1]*base1%mod1;
            pow2[i]=pow2[i-1]*base2%mod2;
        }

        for(int i=1;i<=n;i++){
            ha1[i]=(ha1[i-1]*base1%mod1+s[i])%mod1;
            ha2[i]=(ha2[i-1]*base2%mod2+s[i])%mod2;

            rha1[i]=(rha1[i-1]*base1%mod1+s[n-i+1])%mod1;
            rha2[i]=(rha2[i-1]*base2%mod2+s[n-i+1])%mod2;
        }
    }

    pair<ull,ull> get(int l,int r){
        ull res1=((ha1[r]-ha1[l-1]*pow1[r-l+1])%mod1+mod1)%mod1;
        ull res2=((ha2[r]-ha2[l-1]*pow2[r-l+1])%mod2+mod2)%mod2;

        return {res1,res2};
    }

    //反哈希
    pair<ull,ull> get_rhash(int l,int r){
        ull res1=((rha1[n-l+1]-rha1[n-r]*pow1[r-l+1])%mod1+mod1)%mod1;
        ull res2=((rha2[n-l+1]-rha2[n-r]*pow2[r-l+1])%mod2+mod2)%mod2;

        return {res1,res2};
    }

    //判断回文
    bool is_palindrome(int l,int r){
        return (get(l,r)==get_rhash(l,r));
    }

    pair<ull,ull> add(pair<ull,ull> aa,pair<ull,ull> bb){
        ull res1=(aa.first+bb.first)%mod1;
        ull res2=(aa.second+bb.second)%mod2;

        return {res1,res2};
    }

    //aa *= Base的k次方
	pair<ull, ull> mul(pair<ull, ull> aa, ull kk) {
		ull res1 = aa.first * pow1[kk] % mod1;
		ull res2 = aa.second * pow2[kk] % mod2;
		return {res1, res2};
	}

	//拼接字符串 r1 < l2  s = s1 + s2
	pair<ull, ull> link(int l1, int r1, int l2, int r2) {
		return add(mul(get(l2, r2), r1 - l1 + 1), get(l1, r1));
	}
};
