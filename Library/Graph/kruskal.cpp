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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const int INF=1e9;
const int MAX_N=514514;
const int MAX_E=114514;

struct UnionFind{
	vi par;
	vi rank;

	UnionFind(int n=1){
		init(n);
	}

	// n要素で初期化
	void init(int n=1){
		par.resize(n);
		rank.resize(n);
		REP(i, n){
			par[i]=i;
			rank[i]=0;
		}
	}

	// xの根を求める
	int find(int x){
		if(par[x]==x){
			return x;
		}
		else{
			return par[x]=find(par[x]);
		}
	}

	// xとyが属する集合を併合
	bool unite(int x, int y){
		x=find(x);
		y=find(y);
		if(x==y){
			return false;
		}
		if(rank[x]<rank[y]){
			par[x]=y;
		}
		else{
			par[y]=x;
			if(rank[x]==rank[y]){
				++rank[x];
			}
		}
		return true;
	}

	// xとyが同じ集合に属するか判定
	bool issame(int x, int y){
		return find(x)==find(y);
	}
};

struct edge{
	int u;
	int v;
	int cost;
};

int root[MAX_N], depth[MAX_N];

edge es[MAX_E];
int V, E;

void add_edge(int u, int v, int cost){
	es[E++]={u, v, cost};
	return;
}

bool comp(const edge& e1, const edge& e2){
	return e1.cost<e2.cost;
}

int kruskal(){
	sort(es, es+E, comp);
	UnionFind uf(V);
	int res=0;
	REP(i, E){
		edge e=es[i];
		if(!uf.issame(e.u, e.v)){
			uf.unite(e.u, e.v);
			res+=e.cost;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
