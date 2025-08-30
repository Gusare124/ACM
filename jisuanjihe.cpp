#include<bits/stdc++.h>
using namespace std;
/*
    计算几何
    1. 坐标结构体 point
    2. 两点距离（平方/sqrt后结果）dis dis2
    3. 叉积 [ab]x[ac] [ac在ab逆时针(左侧)为正，否则负]
    4. 求极角
        double atan2(double y,double x);
        long double atan2l(long double y,long double x);
        一象限: [0,pi/2]
        二象限: [pi/2,pi]
        三象限: (-pi,-pi/2]
        四象限: [-pi/2,0]
    5. 极角排序
        (1) 直接求 精度有损耗cmp1
        (2) 利用叉乘排序 如果坐标都是整点无精度损耗cmp2
*/
struct point{int x,y;};
int cross(point a,point b,point c);
int dis2(point a,point b);
double dis(point a,point b);
int cmp1(point a,point b);
int cmp2(point a,point b);
int qua(point a);

vector<point> p;

int cmp2(point a,point b){ //以(0,0)为原点
    point c;
    c.x=c.y=0;
    if(qua(a)==qua(b)){
        if(cross(c,a,b)==0) return a.x<b.x;
        else return cross(c,a,b)>0;
    }
    else return qua(a)<qua(b);
}
int cmp1(point a,point b){ //以(0,0)为原点
    return (atan2(a.y,a.x)==atan2(b.y,b.x)?(a.x<b.x):(atan2(a.y,a.x)<atan2(b.y,b.x)));
}
int qua(point a){
    if(a.y>=0 && a.x>0) return 1;
    else if(a.y>=0 && a.x<=0) return 2;
    else if(a.y<0 && a.x<=0) return 3;
    else return 4;
}

double dis(point a,point b){
    return sqrt(1.0*(b.y-a.y)*(b.y-a.y)+1.0*(a.x-b.x)*(a.x-b.x));
}
int dis2(point a,point b){
    return ((b.y-a.y)*(b.y-a.y)+(a.x-b.x)*(a.x-b.x));
}
int cross(point a,point b,point c){
    return ((c.y-a.y)*(b.x-a.x)-(b.y-a.y)*(c.x-a.x));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    point a,b,c,d,e,tmp;
    a.x=0,a.y=0;
    b.x=1,b.y=0;
    c.x=0,c.y=1;
    d.x=-1,d.y=0;
    e.x=0,e.y=-1;


    p.push_back(a);
    p.push_back(b);
    p.push_back(c);
    p.push_back(d);
    p.push_back(e);
    tmp.x=1,tmp.y=-1;
    p.push_back(tmp);
    tmp.x=2,tmp.y=-2;
    p.push_back(tmp);

    sort(p.begin(),p.end(),cmp1); 
    for(int i=0;i<p.size();i++){
        cerr<<p[i].x<<','<<p[i].y<<'\n';
    }
    cerr<<'\n';

    sort(p.begin(),p.end(),cmp2); 
    for(int i=0;i<p.size();i++){
        cerr<<p[i].x<<','<<p[i].y<<'\n';
    }
    cerr<<'\n';

    return 0;
}