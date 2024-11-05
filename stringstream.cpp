#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    /*
        stringstream读取一行，去空格
    */
    string input;
    getline(cin,input);
    stringstream ss(input);
    string temp;
    while(ss>>temp){
        /*
            ...
        */
    }
    cout<<ss.str()<<'\n'; //打印ss的字符串
    return 0;
}