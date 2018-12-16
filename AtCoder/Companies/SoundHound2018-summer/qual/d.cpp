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

const ll INF=1e18;
const int MAX_V=114514;

struct edge{
	int to;
	int cost[2];
};

int V;
vector<edge> g[MAX_V];
// 頂点sからの最短距離
ll d[2][MAX_V];

void dijkstra(int s, int k){
	// piiのfirstは最短距離、secondは頂点の番号
	priority_queue<pll, vector<pll>, greater<pll>> que;
	fill(d[k], d[k]+V, INF);
	d[k][s]=0;
	que.push(pii(0, s));
	while(!que.empty()){
		pii p=que.top();
		que.pop();
		ll v=p.second;
		if(d[k][v]<p.first){
			continue;
		}
		REP(i, g[v].size()){
			edge e=g[v][i];
			if(d[k][e.to]>d[k][v]+e.cost[k]){
				d[k][e.to]=d[k][v]+e.cost[k];
				que.push(pll(d[k][e.to], e.to));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, s, t, u, v, a, b;
	cin>>n>>m>>s>>t;
	--s;
	--t;
	V=n;
	REP(i, m){
		cin>>u>>v>>a>>b;
		--u;
		--v;
		edge e;
		e.to=v;
		e.cost[0]=a;
		e.cost[1]=b;
		g[u].push_back(e);
		edge e2;
		e2.to=u;
		e2.cost[0]=a;
		e2.cost[1]=b;
		g[v].push_back(e2);
	}
	dijkstra(s, 0);
	dijkstra(t, 1);
	pll sum[MAX_V];
	REP(i, n){
		sum[i]=pll(d[0][i]+d[1][i], i);
	}
	sort(sum, sum+n);
	int cnt=0;
	REP(i, n){
		while(sum[cnt++].second<i){}
		--cnt;
		cnt=min(cnt, n-1);
		cout<<ll(1e15)-sum[cnt].first<<'\n';
	}
	return 0;
}
