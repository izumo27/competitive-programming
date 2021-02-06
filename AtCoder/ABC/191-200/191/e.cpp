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

constexpr ll INF=1e18;

const int MAX_V=2525;

struct edge{
  int to;
  ll cost;
};

int V;
vector<edge> g[MAX_V];
// 頂点sからの最短距離
ll d[MAX_V][MAX_V];

void add_edge(int from, int to, ll cost){
  g[from].push_back({to, cost});
  return;
}

void dijkstra(int s){
  // piiのfirstは最短距離、secondは頂点の番号
  priority_queue<pll, vector<pll>, greater<pll>> que;
  REP(i, V){
    d[s][i]=INF;
  }
  que.push({0ll, s});
  while(!que.empty()){
    pll p=que.top();
    que.pop();
    int v=p.second;
    if(d[s][v]<p.first){
      continue;
    }
    REP(i, g[v].size()){
      edge e=g[v][i];
      if(d[s][e.to]>p.first+e.cost){
        d[s][e.to]=p.first+e.cost;
        que.push({d[s][e.to], e.to});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m;
  cin>>n>>m;
  V=n;
  ll dis[2525][2525];
  REP(i, n){
    REP(j, n){
      dis[i][j]=INF;
    }
  }
  REP(i, m){
    int a, b;
    ll c;
    cin>>a>>b>>c;
    --a;--b;
    CHMIN(dis[a][b], c);
  }
  REP(i, n){
    REP(j, n){
      if(i==j){
        continue;
      }
      if(dis[i][j]!=INF){
        add_edge(i, j, dis[i][j]);
      }
    }
  }
  REP(i, n){
    dijkstra(i);
  }
  REP(i, n){
    if(dis[i][i]!=INF || d[i][i]!=INF){
      cout<<min(dis[i][i], d[i][i])<<'\n';
    }
    else{
      cout<<-1<<'\n';
    }
  }
  return 0;
}
