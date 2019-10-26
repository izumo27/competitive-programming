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

int n;
ll h[114514], s[114514], t[114514];

bool is_ok(ll a){
	REP(i, n){
		t[i]=(a-h[i])/s[i];
	}
	sort(t, t+n);
	REP(i, n){
		if(t[i]<(ll)i){
			return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ll lb=0, ub=0;
	REP(i, n){
		cin>>h[i]>>s[i];
		lb=max(lb, h[i]);
		ub=max(ub, s[i]);
	}
	ub=lb+ub*(ll)(n-1);
	--lb;
	while(ub-lb>1){
		ll mid=(lb+ub)/2;
		if(is_ok(mid)){
			ub=mid;
		}
		else{
			lb=mid;
		}
	}
	cout<<ub<<'\n';
	return 0;
}
