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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n;
	ll a[334][334];
	cin>>n;
	REP(i, n){
		REP(j, n){
			cin>>a[i][j];
		}
	}
	ll ans=0;
	REP(i, n){
		FOR(j, i+1, n){
			ll mi=1e18;
			REP(k, n){
				if(k==i || k==j){
					continue;
				}
				CHMIN(mi, a[i][k]+a[k][j]);
			}
			if(mi<a[i][j]){
				cout<<-1<<'\n';
				return 0;
			}
			if(mi>a[i][j]){
				ans+=a[i][j];
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
