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

ll dp[2][20][2][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin>>a>>b;
	dp[0][0][0][0]=1;
	dp[1][0][0][0]=1;
	REP(x, 2){
		int n=a.size();
		if(x){
			n=b.size();
		}
		REP(i, n){
			REP(j, 2){
				int lim=j ? 9 : a[i]-'0';
				if(x){
					lim=j ? 9 : b[i]-'0';
				}
				REP(k, 2){
					if(k){
						REP(l, lim+1){
							dp[x][i+1][j || l<lim][k]+=dp[x][i][j][k];
						}
					}
					else{
						REP(l, lim+1){
							if(l!=4 && l!=9){
								dp[x][i+1][j || l<lim][k]+=dp[x][i][j][k];
							}
							else{
								dp[x][i+1][j || l<lim][1]+=dp[x][i][j][k];
							}
						}

					}
				}
			}
		}
	}
	ll ans=0;
	int n=b.size();
	REP(j, 2){
		ans+=dp[1][n][j][1];
		// DEBUG(ans);
	}
	n=a.size();
	REP(j, 2){
		ans-=dp[0][n][j][1];
		// DEBUG(ans);
	}
	REP(i, n){
		if(a[i]=='4' || a[i]=='9'){
			++ans;
			break;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
