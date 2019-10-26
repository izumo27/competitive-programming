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

#define DEBUG(x) cout<<#x<<": "<<(x)<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(10)<<fixed;
	int n, m, a[252525], b[252525];
	cin>>n>>m;
	ll suma=0, sumb=0;
	REP(i, n){
		cin>>a[i];
		suma+=a[i];
	}
	REP(i, m){
		cin>>b[i];
		sumb+=b[i];
	}
	sort(a, a+n);
	sort(b, b+m);
	vl cnd1;
	int cnt1=0;
	FOR(i, 1, (1<<n)-1){
		ll tmp=0;
		REP(j, n){
			if(i>>j&1){
				tmp+=a[j];
			}
		}
		if(tmp>=suma-tmp){
			continue;
		}
		cnd1.push_back(tmp);
		++cnt1;
	}
	vl cnd2;
	int cnt2=0;
	FOR(i, 1, (1<<m)-1){
		ll tmp=0;
		REP(j, m){
			if(i>>j&1){
				tmp+=b[j];
			}
		}
		if(tmp>=sumb-tmp){
			continue;
		}
		cnd2.push_back(tmp);
		// DEBUG(tmp);
		++cnt2;
	}
	sort(ALL(cnd1));
	sort(ALL(cnd2));
	int ans=0;
	for(auto & x : cnd1){
		int tmp=upper_bound(ALL(cnd2), x-1)-upper_bound(ALL(cnd2), sumb-suma+x);
		CHMAX(ans, tmp);
		// DEBUG(ans);
	}
	// DEBUG(cnt1);
	double ans2=(double)ans/cnt2;
	cout<<ans2<<'\n';
	return 0;
}
