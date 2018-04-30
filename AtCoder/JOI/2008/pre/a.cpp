#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORR(i, a, b) for(int i=b-1; i>=a; --i)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int v[6]={1, 5, 10, 50, 100, 500};
	cin>>n;
	int ans=0;
	int tmp=1000-n;
	int t;
	FORR(i, 0, 6){
		t=tmp/v[i];
		tmp-=t*v[i];
		ans+=t;
	}
	cout<<ans<<'\n';
	return 0;
}
