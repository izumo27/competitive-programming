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

ll sum[252521], dp1[252521], dp2[252521], dp3[252521];
ll INF=1e16;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int l;
	ll a[252521];
	cin>>l;
	bool ok=false;
	REP(i, l){
		cin>>a[i];
		if(a[i]){
			ok=true;
		}
		sum[i+1]=sum[i]+a[i];
	}
	if(!ok){
		cout<<0<<'\n';
		return 0;
	}
	dp1[0]=dp2[0]=dp3[0]=INF;
	ll ans=INF;
	REP(i, l){
		dp1[i+1]=min(dp1[i], sum[i])+(a[i]==0 ? 2 : a[i]&1);
		dp2[i+1]=min({dp1[i], dp2[i], sum[i]})+(~a[i]&1);
		dp3[i+1]=min({dp1[i], dp2[i], dp3[i], sum[i]})+(a[i]==0 ? 2 : a[i]&1);
		CHMIN(ans, min({dp1[i+1], dp2[i+1], dp3[i+1]})+sum[l]-sum[i+1]);
	}
	cout<<ans<<'\n';
	return 0;
}
