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

ll dp[114514][4];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	pii q[4];
	ll n;
	REP(i, 4){
		cin>>q[i].first;
		q[i].second=(1<<i);
	}
	cin>>n;
	ll m=n*4;
	pii x[4];
	REP(i, 4){
		x[i]=pii(q[i].first*(8>>i), i);
	}
	sort(x, x+4);
	ll ans=0;
	int cnt=0;
	while(m>0){
		ans+=(m/q[x[cnt].second].second)*q[x[cnt].second].first;
		m=m%q[x[cnt].second].second;
		++cnt;
	}
	cout<<ans<<'\n';
	return 0;
}
