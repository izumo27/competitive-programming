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

const ll INF=1e13;
const int MAX_V=114514;

struct edge{
  int to;
  ll cost;
};

int V;
vector<edge> g[2][MAX_V];
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
    int v=p.second;
    if(d[k][v]<p.first){
      continue;
    }
    REP(i, g[k][v].size()){
      edge e=g[k][v][i];
      if(d[k][e.to]>d[k][v]+e.cost){
        d[k][e.to]=d[k][v]+e.cost;
        que.push(pii(d[k][e.to], e.to));
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  ll t, A[114514], a, b, c;
  cin>>n>>m>>t;
  V=n;
  REP(i, n){
    cin>>A[i];
  }
  REP(i, m){
    cin>>a>>b>>c;
    --a;
    --b;
    edge e;
    e.to=b;
    e.cost=c;
    g[0][a].push_back(e);
    edge e2;
    e2.to=a;
    e2.cost=c;
    g[1][b].push_back(e2);
  }
  dijkstra(0, 0);
  dijkstra(0, 1);
  ll ans=0;
  REP(i, n){
    ans=max(ans, (t-d[0][i]-d[1][i])*A[i]);
  }
  cout<<ans<<'\n';
  return 0;
}
