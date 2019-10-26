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
const int MAX_V=114;

// d[i][j]: 辺e=(i, j)のコスト(存在しない場合はINF, d[i][i]=0)
// d[i][i]が負になる場合は負の閉路が存在
int d[MAX_V][MAX_V];
int V;

void warshall_floyd(){
	REP(k, V){
		REP(i, V){
			REP(j, V){
				d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w, c, a;
	cin>>h>>w;
	V=10;
	REP(i, 10){
		REP(j, 10){
			cin>>c;
			d[i][j]=c;
		}
	}
	warshall_floyd();
	int ans=0;
	REP(i, h){
		REP(j, w){
			cin>>a;
			if(a==-1){
				continue;
			}
			ans+=d[a][1];
		}
	}
	cout<<ans<<'\n';
	return 0;
}
