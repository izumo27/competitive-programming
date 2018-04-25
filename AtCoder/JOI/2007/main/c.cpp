#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, m, ans=0;
	ll p[1100];
	cin>>n>>m;
	p[0]=0;
	for(int i=0; i<n; i++) cin>>p[i+1];
	vector<ll> pp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			pp.push_back(p[i]+p[j]);
		}
	}
	sort(pp.begin(), pp.end());
	for(auto i=pp.begin(); i!=pp.end() && *i<=m; i++){
		auto itr=upper_bound(pp.begin(), pp.end(), m-*i);
		if(*itr!=0) ans=max(ans, *(itr-1)+*i);
	}
	cout<<ans<<endl;
	return 0;
}
