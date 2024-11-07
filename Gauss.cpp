#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

const double sml=1e-7;
double a[105][105];

void gauss(ll n);
void solve();

void gauss(ll n){
    for(ll i=1;i<=n;i++){
        //找绝对值最大的系数对应的行
        ll Max=i;
        for(ll j=1;j<=n;j++){
            if(j<i && fabs(a[j][j])>=sml) continue; //如果之前行有主元就跳过
            if(fabs(a[j][i])>fabs(a[Max][i])) Max=j; //如果目前行第i列的系数更大，更新Max
        }

        //将绝对值最大的系数对应的行交换到第i位
        swap(a[Max],a[i]);

        //归一化
        if(abs(a[i][i])>=sml){
            double temp=a[i][i];
            for(ll j=i;j<=n+1;j++){ //将该行后面列归一化
                a[i][j]/=temp;
            }

            for(ll j=1;j<=n;j++){ //
                if(i==j) continue;
                double rate=a[j][i]/a[i][i];
                for(ll k=i;k<=n+1;k++){
                    a[j][k]-=a[i][k]*rate;
                }
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n+1;j++){
            cin>>a[i][j];
        }
    }
    gauss(n);

    //无解-1，多解0，唯一解输出对应值
    bool flag=true;
    for(ll i=1;i<=n;i++){
        if(fabs(a[i][i])<sml && fabs(a[i][n+1])>=sml){
            cout<<-1<<'\n';
            return ;
        }
        if(fabs(a[i][i]<sml)){
            flag=false;
        }
    }
    if(!flag){
        cout<<0<<'\n';
        return ;
    }
    for(ll i=1;i<=n;i++){
        cout<<"x"<<i<<"="<<fixed<<setprecision(2)<<a[i][n+1]<<'\n';
    }
}