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
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int dp[12525][2][114];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int d;
	string n;
	cin>>d>>n;
	dp[0][0][0]=1;
	REP(i, n.size()){
		REP(j, 2){
			int lim=j ? 9 : n[i]-'0';
			REP(k, d){
				REP(l, lim+1){
					(dp[i+1][j || l<lim][(k+l)%d]+=dp[i][j][k])%=MOD;
				}
			}
		}
	}
	int ans=(dp[n.size()][0][0]+dp[n.size()][1][0])%MOD;
	cout<<(ans-1+MOD)%MOD<<'\n';
	return 0;
}
