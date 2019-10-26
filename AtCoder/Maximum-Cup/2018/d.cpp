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

int dp[12525][1333];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, l, x, a;
	cin>>n>>m>>l>>x;
	REP(i, n+1){
		REP(j, m){
			dp[i][j]=x+1;
		}
	}
	dp[0][0]=1;
	REP(i, n){
		cin>>a;
		int t=a%m, t2=a/m;
		REP(j, m){
			if(j>=t){
				dp[i+1][j]=min(dp[i][j], dp[i][j-t]+t2);
			}
			else{
				dp[i+1][j]=min(dp[i][j], dp[i][j-t+m]+t2+1);
			}
		}
	}
	cout<<(dp[n][l]!=0 && dp[n][l]<=x ? "Yes" : "No")<<'\n';
	return 0;
}
