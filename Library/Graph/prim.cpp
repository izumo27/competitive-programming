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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const int INF=1e9;
const int MAX_V=114514;

struct edge{
	int to;
	int cost;
};

int V;
vector<edge> g[MAX_V];
int mincost[MAX_V];

void add_edge(int from, int to, int cost){
	g[from].push_back({to, cost});
	return e;
}

int prim(int s){
	// piiのfirstは最小コスト、secondは頂点の番号
	priority_queue<pii, vector<pii>, greater<pii>> que;
	fill(mincost, mincost+V, INF);
	mincost[0]=0;
	que.push({0, s});
	int res=0;
	while(!que.empty()){
		pii p=que.top();
		que.pop();
		int v=p.second;
		if(mincost[v]<p.first){
			continue;
		}
		res+=mincost[v];
		REP(i, g[v].size()){
			edge e=g[v][i];
			if(mincost[e.to]>mincost[v]+e.cost){
				mincost[e.to]=mincost[v]+e.cost;
				que.push({mincost[e.to], e.to});
			}
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
