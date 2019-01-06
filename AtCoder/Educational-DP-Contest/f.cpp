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

string dp[2][3252];
// int dp2[2][3252];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin>>s>>t;
	int n=s.size(), m=t.size();
	REP(i, n){
		if(i&1){
			REP(j, m){
				if(s[i]==t[j]){
					dp[0][j+1]=dp[1][j]+s[i];
					// dp2[0][j+1]=dp2[1][j]+1;
				}
				else{
					if(dp[0][j].size()>dp[1][j+1].size()){
						dp[0][j+1]=dp[0][j];
						// dp2[0][j+1]=dp2[0][j];
					}
					else{
						dp[0][j+1]=dp[1][j+1];
						// dp2[0][j+1]=dp2[1][j+1];
					}
				}
			}
		}
		else{
			REP(j, m){
				if(s[i]==t[j]){
					dp[1][j+1]=dp[0][j]+s[i];
					// dp2[1][j+1]=dp2[0][j]+1;
				}
				else{
					if(dp[1][j].size()>dp[0][j+1].size()){
						dp[1][j+1]=dp[1][j];
						// dp2[1][j+1]=dp2[1][j];
					}
					else{
						dp[1][j+1]=dp[0][j+1];
						// dp2[1][j+1]=dp2[0][j+1];
					}
				}
			}
		}
	}
	cout<<dp[n&1][m]<<'\n';
	return 0;
}
