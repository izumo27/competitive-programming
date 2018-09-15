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
#define CHMAX(a, b) a=max((a), (b))

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, C, s, t, c, stc[40][114514];
	cin>>n>>C;
	int m1, m2;
	REP(i, n){
		cin>>s>>t>>c;
		FOR(j, s-1, t){
			stc[c-1][j]=1;
		}
		m1=min(m1, s-1);
		m2=max(m2, t);
	}
	int ans=0;
	FOR(i, m1, m2){
		int cnt=0;
		REP(j, C){
			cnt+=stc[j][i];
		}
		ans=max(ans, cnt);
	}
	cout<<ans<<'\n';
	return 0;
}