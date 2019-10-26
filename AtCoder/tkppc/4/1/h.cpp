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
constexpr int MAX_V=252525;

struct edge{
  int to;
  ll cost;
  ll D;
};

int n, m, a, b;
ll k, t[252525], c, D;

int V;
vector<edge> g[MAX_V];
// 頂点sからの最短距離
ll d[MAX_V];

void add_edge(int from, int to, ll cost, ll D){
  g[from].push_back({to, cost, D});
  return;
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
    ll v=p.second;
    if(d[v]<p.first){
      continue;
    }
    REP(i, g[v].size()){
      edge e=g[v][i];
      ll tmp=(d[v]==0 ? e.cost+t[e.to] : ((d[v]-1)/e.D+1)*e.D+e.cost+t[e.to]);
      if(d[e.to]>tmp){
        d[e.to]=tmp;
        que.push({d[e.to], e.to});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n>>m>>k;
  REP(i, n-2){
    cin>>t[i+1];
  }
  REP(i, m){
    cin>>a>>b>>c>>D;
    --a;--b;
    add_edge(a, b, c, D);
    add_edge(b, a, c, D);
  }
  V=n;
  dijkstra(0);
  // REP(i, n){
  //   cout<<d[i]<<" \n"[i==n-1];
  // }
  cout<<(d[n-1]<=k ? d[n-1] : -1)<<'\n';
  return 0;
}
