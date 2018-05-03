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
	char c[10][10];
	REP(i, 2){
		REP(j, 3) cin>>c[i][j];
	}
	bool ok=true;
	REP(i, 3){
		if(c[0][i]!=c[1][2-i]) ok=false;
	}
	ok ? cout<<"YES"<<'\n' : cout<<"NO"<<'\n';
	return 0;
}
