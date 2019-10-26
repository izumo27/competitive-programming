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

struct edge{
	int to;
	int cost;
};

vector<edge> g[114514];

void add_edge(int from, int to, int cost){
	g[from].push_back({to, cost});
	return;
}

int ans[114514];

void dfs(int s){
	for(auto x : g[s]){
		if(ans[x.to]!=-1){
			continue;
		}
		if(x.cost&1){
			if(ans[s]){
				ans[x.to]=0;
			}
			else{
				ans[x.to]=1;
			}
			dfs(x.to);
		}
		else{
			if(ans[s]){
				ans[x.to]=1;
			}
			else{
				ans[x.to]=0;
			}
			dfs(x.to);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, u, v, w;
	cin>>n;
	REP(i, n-1){
		cin>>u>>v>>w;
		--u;
		--v;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	REP(i, n){
		ans[i]=-1;
	}
	ans[0]=0;
	dfs(0);
	REP(i, n){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
