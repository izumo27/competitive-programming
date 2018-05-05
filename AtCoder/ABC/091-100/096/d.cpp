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

bool f[55556];

void po(){
	FOR(i, 2, 55556){
		if(!f[i]){
			for(int j=i+i; j<=55555; j+=i) f[j]=true;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	po();
	int a[60];
	int cnt=0;
	FOR(i, 2, 55556){
		if(!f[i] && i%5==1){
			a[cnt]=i;
			++cnt;
			if(cnt>=n) break;
		}
	}
	REP(i, n) cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}
