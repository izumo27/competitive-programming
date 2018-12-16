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

int dp[114][114][114];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b, c, w, x, y, z;
	cin>>n>>m;
	REP(i, n){
		cin>>a>>b>>c>>w;
		dp[a][b][c]=max(dp[a][b][c], w);
	}
	REP(i, 101){
		REP(j, 101){
			REP(k, 101){
				if(i>0){
					dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k]);
				}
				if(j>0){
					dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k]);
				}
				if(k>0){
					dp[i][j][k]=max(dp[i][j][k], dp[i][j][k-1]);
				}
			}
		}
	}
	REP(i, m){
		cin>>x>>y>>z;
		cout<<dp[x][y][z]<<'\n';
	}
	return 0;
}
