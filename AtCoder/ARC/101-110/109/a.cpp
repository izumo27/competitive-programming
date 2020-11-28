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

// constexpr ll MOD=1000000007ll;
constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

struct edge{
  int to;
  int cost;
};

int V;
constexpr int MAX_V=252;
constexpr int INF=1e9;
vector<edge> g[MAX_V];
// 頂点sからの最短距離
int d[MAX_V];

void add_edge(int from, int to, int cost){
  g[from].push_back({to, cost});
  return;
}

void dijkstra(int s){
  // piiのfirstは最短距離、secondは頂点の番号
  priority_queue<pii, vector<pii>, greater<pii>> que;
  fill(d, d+V, INF);
  d[s]=0;
  que.push({0, s});
  while(!que.empty()){
    pii p=que.top();
    que.pop();
    int v=p.second;
    if(d[v]<p.first){
      continue;
    }
    REP(i, g[v].size()){
      edge e=g[v][i];
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
  int a, b, x, y;
  cin>>a>>b>>x>>y;
  --a;--b;b+=100;
  V=200;
  REP(i, 100){
    add_edge(i, i+100, x);
    add_edge(i+100, i, x);
  }
  REP(i, 99){
    add_edge(i+1, i+100, x);
    add_edge(i+100, i+1, x);
  }
  REP(i, 99){
    add_edge(i, i+1, y);
    add_edge(i+1, i, y);
    add_edge(i+100, i+101, y);
    add_edge(i+101, i+100, y);
  }
  dijkstra(a);
  cout<<d[b]<<'\n';
  return 0;
}
