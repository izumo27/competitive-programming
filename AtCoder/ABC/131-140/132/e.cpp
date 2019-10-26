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

int n, m, u, v, s, t;
int d[125252][3];
vi g[125252];
constexpr int INF=1e9;

void bfs(){
	queue<int> q;
	q.push(s);
	while(q.size()){
		int x=q.front();
		q.pop();
		for(auto y : g[x]){
			REP(i, 3){
				if(d[x][i]+1<d[y][(i+1)%3]){
					d[y][(i+1)%3]=d[x][i]+1;
					q.push(y);
				}
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	cin>>n>>m;
	REP(i, m){
		cin>>u>>v;
		--u;
		--v;
		g[u].push_back(v);
	}
	cin>>s>>t;
	--s;
	--t;
	REP(i, n){
		REP(j, 3){
			d[i][j]=INF;
		}
	}
	d[s][0]=0;
	bfs();
	// REP(i, n){
	// 	REP(j, 3){
	// 		cout<<d[i][j]<<" \n"[j==2];
	// 	}
	// }
	if(d[t][0]!=INF){
		cout<<d[t][0]/3<<'\n';
	}
	else{
		cout<<-1<<'\n';
	}
	return 0;
}
