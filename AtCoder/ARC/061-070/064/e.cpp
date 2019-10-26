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

const double INF=2e18;
const int MAX_V=1333;

struct edge{
	int to;
	double cost;
};

int V;
vector<edge> g[MAX_V];
// 頂点sからの最短距離
double d[MAX_V];
int n;
double x[1333], y[1333], r[1333];

void add_edge(int from, int to){
	double cost=max(0.0, sqrt((x[from]-x[to])*(x[from]-x[to])+(y[from]-y[to])*(y[from]-y[to]))-(r[from]+r[to]));
	g[from].push_back({to, cost});
	return;
}

void dijkstra(int s){
	// piiのfirstは最短距離、secondは頂点の番号
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> que;
	fill(d, d+V, INF);
	d[s]=0;
	que.emplace(0, s);
	while(!que.empty()){
		pair<double, int> p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first){
			continue;
		}
		REP(i, g[v].size()){
			edge e=g[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.emplace(d[e.to], e.to);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(20)<<fixed;
	double tx, ty;
	cin>>x[0]>>y[0]>>tx>>ty>>n;
	x[n+1]=tx;
	y[n+1]=ty;
	r[0]=r[n+1]=0;
	V=n+2;
	FOR(i, 1, n+1){
		cin>>x[i]>>y[i]>>r[i];
	}
	REP(i, V){
		REP(j, V){
			if(i!=j){
				add_edge(i, j);
			}
		}
	}
	dijkstra(0);
	// REP(i, V){
	// 	cout<<d[i]<<'\n';
	// }
	cout<<d[n+1]<<'\n';
	return 0;
}
