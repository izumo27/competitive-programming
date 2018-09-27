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

double dp[114][64][64][64];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a=0, b=0, c=0;
	ll d;
	cin>>n>>d;
	while(d%2==0){
		++a;
		d>>=1;
	}
	while(d%3==0){
		++b;
		d/=3;
	}
	while(d%5==0){
		++c;
		d/=5;
	}
	if(d!=1){
		cout<<0<<'\n';
		return 0;
	}
	dp[0][0][0][0]=1;
	REP(i, n){
		REP(j, a+1){
			REP(k, b+1){
				REP(l, c+1){
					double p=dp[i][j][k][l]/6.0;
					dp[i+1][j][k][l]+=p;
					dp[i+1][min(j+1, a)][k][l]+=p;
					dp[i+1][j][min(k+1, b)][l]+=p;
					dp[i+1][min(j+2, a)][k][l]+=p;
					dp[i+1][j][k][min(l+1, c)]+=p;
					dp[i+1][min(j+1, a)][min(k+1, b)][l]+=p;
				}
			}
		}
	}
	cout<<dp[n][a][b][c]<<'\n';
	return 0;
}
