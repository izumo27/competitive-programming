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

constexpr ll INF=1e9;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(10)<<fixed;
	int n;
	double x, y;
	char d;
	cin>>n;
	double LL=INF, L=INF, LR=INF;
	double RL=-INF, R=-INF, RR=-INF;
	double DD=INF, D=INF, DU=INF;
	double UD=-INF, U=-INF, UU=-INF;
	REP(i, n){
		cin>>x>>y>>d;
		if(d=='R'){
			CHMIN(LR, x);
			CHMAX(RR, x);
			CHMIN(D, y);
			CHMAX(U, y);
		}
		if(d=='L'){
			CHMIN(LL, x);
			CHMAX(RL, x);
			CHMIN(D, y);
			CHMAX(U, y);
		}
		if(d=='U'){
			CHMIN(DU, y);
			CHMAX(UU, y);
			CHMIN(L, x);
			CHMAX(R, x);
		}
		if(d=='D'){
			CHMIN(DD, y);
			CHMAX(UD, y);
			CHMIN(L, x);
			CHMAX(R, x);
		}
	}
	double ans=4*INF*INF;
	REP(i, 4e8){
		double t=i*0.5;
		double xmi=min({L, LL-t, LR+t});
		double xma=max({R, RL-t, RR+t});
		double ymi=min({D, DD-t, DU+t});
		double yma=max({U, UD-t, UU+t});
		CHMIN(ans, (xma-xmi)*(yma-ymi));
	}
	cout<<ans<<'\n';
	return 0;
}
