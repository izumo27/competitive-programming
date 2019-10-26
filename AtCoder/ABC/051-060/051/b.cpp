#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int k, s, x, y, ans=0;
	cin>>k>>s;
	for(x=0; x<=k; x++){
		for(y=0; y<=k; y++){
			if(x+y<=s && x+y+k>=s) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}