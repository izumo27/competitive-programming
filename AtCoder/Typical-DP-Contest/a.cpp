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
#define CHMAX(a, b) a=min((a), (b))

const int MOD=1000000007;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int n, p[114];
bool dp[114][11000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	REP(i, n) cin>>p[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0]=true;
	REP(i, n){
		REP(j, n*110){
			dp[i+1][j]=dp[i][j];
			if(j>=p[i]) dp[i+1][j]|=dp[i][j-p[i]];
		}
	}
	int ans=0;
	REP(i, n*110){
		if(dp[n][i]) ++ans;
	}
	cout<<ans<<'\n';
	return 0;
}
