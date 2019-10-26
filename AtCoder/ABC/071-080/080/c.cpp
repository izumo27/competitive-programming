#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)

#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

#define CHMIN(a, b) a=min((a), (b))
#define CHMAX(a, b) a=min((a), (b))

const int MOD=1000000007;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, f[114][20], p[114][20];
	cin>>n;
	REP(i, n){
		REP(j, 10) cin>>f[i][j];
	}
	REP(i, n){
		REP(j, 11) cin>>p[i][j];
	}
	int ans=-(1<<30);
	for(int i=1; i<1<<10; ++i){
		int tmp=0;
		REP(j, n){
			int tmp1=0;
			REP(k, 10) if((i>>k&1) && f[j][k]) ++tmp1;
			tmp+=p[j][tmp1];
		}
		ans=max(ans, tmp);
	}
	cout<<ans<<'\n';
	return 0;
}
