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

double dp[3252][3252];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	double p;
	cin>>n;
	dp[0][0]=1;
	REP(i, n){
		cin>>p;
		REP(j, i+1){
			dp[i+1][j]+=dp[i][j]*(1-p);
			dp[i+1][j+1]+=dp[i][j]*p;
		}
	}
	double ans=0;
	FOR(i, n/2+1, n+1){
		ans+=dp[n][i];
	}
	cout<<fixed<<setprecision(12)<<ans<<'\n';
	return 0;
}
