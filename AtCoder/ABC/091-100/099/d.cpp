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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c, d[40][40], C, t[10][40];
	cin>>n>>c;
	REP(i, c){
		REP(j, c){
			cin>>d[i][j];
		}
	}
	REP(i, n){
		REP(j, n){
			cin>>C;
			++t[(i+j)%3][C-1];
		}
	}
	int ans=1<<30;
	REP(i, c){
		REP(j, c){
			REP(k, c){
				if(i!=j && j!=k && k!=i){
					int tmp=0;
					REP(l, c){
						tmp+=d[l][i]*t[0][l];
						tmp+=d[l][j]*t[1][l];
						tmp+=d[l][k]*t[2][l];
					}
					ans=min(ans, tmp);
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
