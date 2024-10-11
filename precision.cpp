#include<bits/stdc++.h>
using namespace std;
int main(){
    double num=1.035125;
    int n=2;
    /*
        有四舍五入

        fixed:小数位
        无fixed:有效位数

        scientific:科学记数法

        setprecision(n):精度为n

    */
    cout<<fixed<<setprecision(n)<<num<<'\n';
    cout<<scientific<<setprecision(n)<<num<<'\n';  //控制单行cout输出，输出为科学计数法，结尾保留n位小数
    cout<<setprecision(n)<<num<<'\n';  //区别于以上两种方法，此方法可以设置当前输出流的全局精度，而不只是针对某一个特定输出

    /*
        1.04
        1.04e+00
        1.04e+00
    */
    return 0;
}
