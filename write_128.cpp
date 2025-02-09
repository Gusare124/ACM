#include<bits/stdc++.h>
using namespace std;

void write(__int128 x);

void write(__int128 x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
