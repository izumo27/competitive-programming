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

constexpr ll INF=1e18;
constexpr int MAX_V=2525;

struct edge{
	int to;
	ll cost;
};

int V;
// 頂点sからの最短距離
ll d[MAX_V];
vector<edge> g[MAX_V], g2[MAX_V];
bool can[2525], can2[2525];

void add_edge(int from, int to, ll cost){
	g[from].push_back({to, cost});
	return;
}

void add_edge2(int from, int to, ll cost){
	g2[from].push_back({to, cost});
	return;
}

struct edge2 {
	int from;
	int to;
 	ll cost;
};

// 辺
edge2 es[5252];

// 最短距離
// int d[MAX_V];
int E;

void add_edge3(int from, int to, int cost){
	es[E++]={from, to, cost};
	return;
}

// 負の閉路があるか判定
bool find_negative_loop(){
	memset(d, 0, sizeof(d));
	REP(i, V){
		REP(j, E){
			edge2 e=es[j];
			if(!can[e.to] || !can2[e.to] || !can[e.from] || !can2[e.from]){
				continue;
			}
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				if(i==V-1){
					return true;
				}
			}
		}
	}
	return false;
}

void dijkstra(int s){
	// piiのfirstは最短距離、secondは頂点の番号
	priority_queue<pll, vector<pll>, greater<pll>> que;
	fill(d, d+V, INF);
	d[s]=0;
	que.push({0, s});
	while(!que.empty()){
		pll p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first){
			continue;
		}
		REP(i, g[v].size()){
			edge e=g[v][i];
			if(!can[e.to] || !can2[e.to]){
				continue;
			}
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push({d[e.to], e.to});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, m, a, b;
	ll p, c;
	cin>>n>>m>>p;
	REP(i, m){
		cin>>a>>b>>c;
		--a;--b;
		add_edge(a, b, p-c);
		add_edge2(b, a, p-c);
		add_edge3(a, b, p-c);
	}
	V=n;
	queue<int> q;
	q.push(n-1);
	can[n-1]=true;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(auto & y : g2[x]){
			if(can[y.to]){
				continue;
			}
			can[y.to]=true;
			q.push(y.to);
		}
	}
	queue<int> q2;
	q2.push(0);
	can2[0]=true;
	while(q2.size()){
		int x=q2.front();
		q2.pop();
		for(auto & y : g[x]){
			if(can2[y.to]){
				continue;
			}
			can2[y.to]=true;
			q2.push(y.to);
		}
	}
	if(!can[0] || find_negative_loop()){
		cout<<-1<<'\n';
		return 0;
	}
	dijkstra(0);
	cout<<max(0ll, -d[n-1])<<'\n';
	return 0;
}
