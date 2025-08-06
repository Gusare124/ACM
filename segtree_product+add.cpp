#include<bits/stdc++.h>
#define LEN 100000
#define ll long long
ll a[LEN],tree[(LEN<<2)+5],mark1[(LEN<<2)+5],mark2[(LEN<<2)+5];
ll n,q,mod;
using namespace std;

void push_down(ll p,ll len){
    tree[p<<1]=(tree[p<<1]*mark2[p]+(len-(len>>1))*mark1[p])%mod;   //mark2
    tree[(p<<1)+1]=(tree[(p<<1)+1]*mark2[p]+(len>>1)*mark1[p])%mod;

    mark2[p<<1]=mark2[p<<1]*mark2[p]%mod;
    mark2[(p<<1)+1]=mark2[(p<<1)+1]*mark2[p]%mod;

    mark1[p<<1]=(mark1[p<<1]*mark2[p]%mod+mark1[p])%mod;
    mark1[(p<<1)+1]=(mark1[(p<<1)+1]*mark2[p]%mod+mark1[p])%mod;                //mark2

    mark1[p]=0;
    mark2[p]=1;
}

void update1(ll l,ll r,ll d,ll cl=1,ll cr=n,ll p=1){
    if(cl>r || cr<l){
        return ;
    } else if(l<=cl && cr<=r){
        tree[p]+=(cr-cl+1)*d;
        tree[p]%=mod;
        if(cl<cr){
            mark1[p]+=d;
            mark1[p]%=mod;
        }
    } else {
        ll mid=(cl+cr)>>1;
        push_down(p,cr-cl+1);
        update1(l,r,d,cl,mid,p<<1);
        update1(l,r,d,mid+1,cr,(p<<1)+1);
        tree[p]=tree[p<<1]+tree[(p<<1)+1];
        tree[p]%=mod;
    }
}

void update2(ll l,ll r,ll k,ll cl=1,ll cr=n,ll p=1){
    if(cl>r || cr<l){
        return ;
    } else if(l<=cl && cr<=r){
        tree[p]=tree[p]*k%mod;
        if(cl<cr){
            mark2[p]=mark2[p]*k%mod;
            mark1[p]=mark1[p]*k%mod;    //upd2里mark1也要更新
        }
    } else {
        ll mid=(cl+cr)>>1;
        push_down(p,cr-cl+1);
        update2(l,r,k,cl,mid,p<<1);
        update2(l,r,k,mid+1,cr,(p<<1)+1);
        tree[p]=tree[p<<1]+tree[(p<<1)+1];
        tree[p]%=mod;
    }
}

void build(ll l=1,ll r=n,ll p=1){
    if(l==r){
        tree[p]=a[l]%mod;
    } else {
        ll mid=(l+r)>>1;
        build(l,mid,p<<1);
        build(mid+1,r,(p<<1)+1);
        tree[p]=(tree[p<<1]+tree[(p<<1)+1])%mod;
    }
}

ll query(ll l,ll r,ll cl=1,ll cr=n,ll p=1){
    if(cl>r || cr<l){
        return 0;
    } else if(cl>=l && cr<=r){
        return tree[p];
    } else {
        ll mid=(cl+cr)>>1;
        push_down(p,cr-cl+1);
        return query(l,r,cl,mid,p<<1)+query(l,r,mid+1,cr,(p<<1)+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin>>n>>q>>mod;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<=(LEN<<2)+4;i++){
        mark2[i]=1;
    }

    build();

    while(q--){
        ll opr,x,y,k;
        cin>>opr>>x>>y;
        if(opr==1){
            cin>>k;
            update2(x,y,k);
        } else if(opr==2){
            cin>>k;
            update1(x,y,k);
        } else {
            cout<<query(x,y)%mod<<'\n';
        }
    }

    return 0;
}
