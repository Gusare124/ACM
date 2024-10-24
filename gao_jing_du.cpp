#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    高精度板子
    （1）构造：低精到高精
    （2）构造：string高精到结构体高精
    （3）高精+高精
    （4）高精+低精
    （5）高精*高精
    （6）高精*低精
    （7）高精/低精（整除）
    （8）打印高精
*/
struct num{
    int len,s[100005];

    num(ll a=0){ //构造函数(低精变高精)
        len=0;
        memset(s,0,sizeof(s));
        while(a){
            s[++len]=a%10;
            a/=10;
        }
    }

    num(string str){ //构造(string高精->结构体高精)
        ll sz=str.size();
        len=sz;
        for(ll i=0;i<sz;i++){
            s[sz-i]=str[i]-'0';
        }
    }

    //高精+高精
    num operator+(const num &a) const{
        num c;
        ll x=0;
        c.len=max(len,a.len);
        for(ll i=1;i<=c.len;i++){
            c.s[i]=a.s[i]+s[i];
        }
        for(ll i=1;i<=c.len;i++){
            x+=c.s[i];
            c.s[i]=x%10;
            x/=10;
        }
        while(x!=0){
            c.s[++c.len]=x%10;
            x/=10;
        }
        return c;
    }

    //高精+低精
    num operator+(const ll &u) const{
        num c;
        c.len=len;
        ll x=0;
        x+=u;
        for(ll i=1;i<=c.len;i++){
            x+=s[i];
            c.s[i]=x%10;
            x/=10;
        }
        while(x!=0){
            c.s[++c.len]=x%10;
            x/=10;
        }
        return c;
    }

    //高精*高精
    num operator*(const num &a) const{
        num c;
        ll x;
        for(ll i=1;i<=a.len;i++){
            x=0;
            for(ll j=1;j<=len;j++){
                c.s[i+j-1]+=a.s[i]*s[j]+x;
                x=c.s[i+j-1]/10;
                c.s[i+j-1]%=10;
            }
            c.s[i+len]=x;
        }
        c.len=a.len+len;
        while(!c.s[c.len] && len!=1){
            c.len--;
        }
        return c;
    }

    //高精*低精
    num operator*(const ll &u)const{
        num c;
        c.len=len;
        ll x=0;
        for(ll i=1;i<=len;i++){
            c.s[i]=s[i]*u;
        }
        for(ll i=1;i<=c.len;i++){
            x+=c.s[i];
            c.s[i]=x%10;
            x/=10;
        }
        while(x!=0){
            c.s[++c.len]=x%10;
            x/=10;
        }
        return c;
    }

    //高精/低精(整除)
    num operator/(const ll &a)const{
        num c;
        ll x=0;
        c.len=len;
        for(ll i=c.len;i>=1;i--){
            x=x*10+s[i];
            c.s[i]=x/a;
            x%=a;
        }
        while(!c.s[c.len] && c.len!=1){
            c.len--;
        }
        return c;
    }

    //打印高精(自带换行)
    void print()const{
        for(ll i=len;i>=1;i--){
            cout<<s[i];
        }
        cout<<'\n';
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin>>s;

    num tst(s);
    tst.print();

    // tst=tst*tst;
    // tst.print();

    // tst=tst/10;
    // tst.print();

    // tst=tst+tst;
    // tst.print();

    return 0;
}