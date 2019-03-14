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

const double INF=1e9;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(10)<<fixed;
	int n, x;
	cin>>n;
	int st=0;
	REP(i, n){
		cin>>x;
		st|=1<<x;
	}
	st<<=1;
	double dp[1<<17];
	FOR(i, 1, 1<<17){
		dp[i]=INF;
		REP(j, 16){
			int sub=i>>j&7;
			if(!sub){
				continue;
			}
			double res=0;
			int cnt=0;
			REP(k, 3){
				if(sub>>k&1){
					++cnt;
					res+=dp[i-(1<<(j+k))];
				}
			}
			CHMIN(dp[i], res/cnt+3./cnt);
		}
	}
	cout<<dp[st]<<'\n';
	return 0;
}
