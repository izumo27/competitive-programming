#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll x, y, i=0;
	cin>>x>>y;
	while(true){
		if(x>y) break;
		x=x<<1;
		i++;
	}
	cout<<i<<endl;
	return 0;
}