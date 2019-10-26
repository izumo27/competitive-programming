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

int dp[1333][1333];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int A, B, a[1333], b[1333];
	cin>>A>>B;
	REP(i, A){
		cin>>a[i];
	}
	REP(i, B){
		cin>>b[i];
	}
	dp[A][B]=0;
	FORR(j, 0, B){
		if((A+j)&1){
			dp[A][j]=dp[A][j+1];
		}
		else{
			dp[A][j]=dp[A][j+1]+b[j];
		}
	}
	FORR(i, 0, A){
		if((i+B)&1){
			dp[i][B]=dp[i+1][B];
		}
		else{
			dp[i][B]=dp[i+1][B]+a[i];
		}
	}
	FORR(i, 0, A){
		FORR(j, 0, B){
			if((i+j)&1){
				dp[i][j]=min(dp[i+1][j], dp[i][j+1]);
			}
			else{
				dp[i][j]=max(dp[i+1][j]+a[i], dp[i][j+1]+b[j]);
			}
		}
	}
	cout<<dp[0][0]<<'\n';
	return 0;
}
