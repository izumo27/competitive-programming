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

const int INF=1e9;
int dp[2525][2525], x[2525], y[2525], xx[2525][2525], xy[2525][2525], yx[2525][2525], yy[2525][2525];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a[4334];
	char c[4334];
	cin>>n;
	REP(i, n<<1){
		cin>>c[i]>>a[i];
		--a[i];
		if(c[i]=='W'){
			x[a[i]]=i;
		}
		else{
			y[a[i]]=i;
		}
	}
	REP(i, n){
		REP(j, n){
			xx[i][j+1]=xx[i][j]+(x[i]<x[j]);
			xy[i][j+1]=xy[i][j]+(x[i]<y[j]);
			yx[i][j+1]=yx[i][j]+(y[i]<x[j]);
			yy[i][j+1]=yy[i][j]+(y[i]<y[j]);
		}
	}
	REP(i, n+1){
		REP(j, n+1){
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	REP(i, n+1){
		REP(j, n+1){
			if(i<n){
				dp[i+1][j]=min(dp[i+1][j], dp[i][j]+xx[i][i]+xy[i][j]);
			}
			if(j<n){
				dp[i][j+1]=min(dp[i][j+1], dp[i][j]+yy[j][j]+yx[j][i]);
			}
		}
	}
	cout<<dp[n][n]<<'\n';
	return 0;
}
