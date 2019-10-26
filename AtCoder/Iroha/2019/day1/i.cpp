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

constexpr int INF=1e9;
constexpr int MAX_V=114514;

int V;
vector<edge> g[MAX_V];
// 頂点sからの最短距離
int d[MAX_V];

void add_edge(int from, int to, int cost){
  g[from].push_back({to, cost});
  return;
}

void dijkstra(int s){
  // piiのfirstは最短距離、secondは頂点の番号
  priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int ,pii>>> que;
  fill(d, d+V, INF);
  d[s]=0;
  que.push({0, {s, 0}});
  while(!que.empty()){
    auto p=que.top();
    que.pop();
    pii v=p.second;
    if(d[v.first]<p.first){
      continue;
    }
    REP(i, g[v.first].size()){
      edge e=g[v.first][i];
      if(d[e.to]>d[v.first]+(e.cost!=v.second)){
        // DEBUG(d[e.to]);
        d[e.to]=d[v.first]+(e.cost!=v.second);
        que.push({d[e.to], {e.to, e.cost}});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m, k, a, b, c;
  cin>>n>>m>>k;
  REP(i, m){
    cin>>a>>b>>c;
    --a;
    --b;
    add_edge(a, b, c);
    add_edge(b, a, c);
  }
  V=n;
  dijkstra(0);
  cout<<(d[n-1]<INF ? d[n-1]*k : -1)<<'\n';
  return 0;
}
