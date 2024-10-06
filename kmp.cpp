#include<bits/stdc++.h>
#define ll long long
#define debug(x) cerr<<#x<<'='<<x<<'\n';
using namespace std;
void kmp(string t,string p){
    string s=t+'#'+p;
    ll len=s.size();
    vector<ll> nxt(len,0);
    for(ll i=1,j=0;i<=len;i++){
        while(j && s[i]!=s[j]){
            j=nxt[j-1]; //j-1!!!!
        }
        if(s[i]==s[j]){
            j++;
        }
        nxt[i]=j;
    }
}
void kmp(string s){
    ll len=s.size();
    vector<ll> nxt(len,0);
    for(ll i=1,j=0;i<len;i++){
        while(j && s[i]!=s[j]){
            j=nxt[j-1]; //j-1!!!!
        }
        if(s[i]==s[j]){
            j++;
        }
        nxt[i]=j;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    kmp("aba","abaaaba");
}