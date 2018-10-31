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
	int n, x, w[40];
	cin>>n>>x;
	REP(i, n){
		cin>>w[i];
	}
	int m=n/2;
	vi v;
	REP(i, 1<<m){
		int tmp=0;
		REP(j, m){
			if(i>>j&1){
				tmp+=w[j];
			}
		}
		v.push_back(tmp);
	}
	sort(ALL(v));
	int m2=n-m;
	ll ans=0;
	REP(i, 1<<m2){
		int tmp=0;
		REP(j, m2){
			if(i>>j&1){
				tmp+=w[j+m];
			}
		}
		ans+=(ll)(upper_bound(ALL(v), x-tmp)-lower_bound(ALL(v), x-tmp));
	}
	cout<<ans<<'\n';
	return 0;
}
