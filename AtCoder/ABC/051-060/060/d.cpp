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

#define DEBUG(x) cout<<#x<<": "<<(x)<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int sum[4][110], sz[4];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, W, v[110];
	ll w[110];
	cin>>n>>W;
	REP(i, n){
		cin>>w[i]>>v[i];
	}
	vi cnt[4];
	cnt[0].push_back(v[0]);
	sz[0]=1;
	REP(i, n-1){
		cnt[w[i+1]-w[0]].push_back(v[i+1]);
		++sz[w[i+1]-w[0]];
	}
	REP(i, 4){
		sort(ALL(cnt[i]), greater<int>());
	}
	REP(i, 4){
		REP(j, sz[i]){
			sum[i][j+1]=sum[i][j]+cnt[i][j];
		}
	}
	int ans=0;
	REP(i, sz[0]+1){
		REP(j, sz[1]+1){
			REP(k, sz[2]+1){
				REP(l, sz[3]+1){
					ll tmp=(i+j+k+l)*w[0]+j+k*2+l*3;
					if(tmp<=W){
						CHMAX(ans, sum[0][i]+sum[1][j]+sum[2][k]+sum[3][l]);
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
