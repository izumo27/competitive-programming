#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORR(i, a, b) for(int i=b-1; i>=a; --i)

int n;
ll c;
ll x[110000], v[110000], s[110000], a1[110000], a2[110000], b1[110000], b2[110000];
ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>c;
	REP(i, n){
		cin>>x[i+1]>>v[i+1];
		s[i+1]=s[i]+v[i+1];
		a1[i+1]=max(a1[i], s[i+1]-x[i+1]);
		a2[i+1]=max(a2[i], s[i+1]-x[i+1]*2);
	}
	FORR(i, 1, n+1){
		b1[i]=max(b1[i+1], s[n]-s[i-1]-(c-x[i]));
		b2[i]=max(b2[i+1], s[n]-s[i-1]-(c-x[i])*2);
	}
	REP(i, n+1) ans=max(ans, max(a1[i]+b2[i+1], a2[i]+b1[i+1]));
	cout<<ans<<'\n';
	return 0;
}
