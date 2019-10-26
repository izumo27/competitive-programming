#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll mod=1000000007;
	ll n, i, ans=1;
	cin>>n;
	for(i=1; i<=n; i++){
		ans=ans*i%mod;
	}
	cout<<ans<<endl;
	return 0;
}
