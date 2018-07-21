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

vector<int> g[114514];
int color[114514];

bool dfs(int v, int c){
	color[v]=c;
	REP(i, g[v].size()){
		if(color[g[v][i]]==c){
			return false;
		}
		if(color[g[v][i]]==0 && !dfs(g[v][i], -c)){
			return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll v, m;
	int a, b;
	cin>>v>>m;
	REP(i, m){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(!dfs(a, 1)){
		// 二部グラフではない

	}
	// グラフが連結でないとき
	// REP(i, v){
	// 	if(color[i]==0){
	// 		if(!dfs(i, 1)){
	// 			// 二部グラフではない
	//
	// 		}
	// 	}
	// }
	return 0;
}
