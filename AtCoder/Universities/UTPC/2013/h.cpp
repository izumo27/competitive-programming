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
const int MAX_E=252525;
const int MAX_V=2525;

struct edge {
  int from;
  int to;
  int cost;
};

// 辺
edge es[MAX_E];

// 最短距離
ll d[MAX_V];
int V, E;

edge make_edge(int from, int to, int cost){
  edge e;
  e.from=from;
  e.to=to;
  e.cost=cost;
  return e;
}

void shortest_path(int s){
  fill(d, d+V, INF);
  d[s]=0;
  while(true){
    bool update=false;
    REP(i, E){
      edge e=es[i];
      if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost){
        d[e.to]=d[e.from]+e.cost;
        update=true;
      }
    }
    if(!update){
      break;
    }
  }
}

// 負の閉路があるか判定
bool find_negative_loop(){
  memset(d, 0, sizeof(d));
  REP(i, V){
    REP(j, E){
      edge e=es[j];
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p, q, x, y, a, b;
  cin>>n>>m;
  int z=n*2;
  V=n*2+1;
  E=n*4+m*2;
  REP(i, n){
    cin>>p;
    es[i*2]=make_edge(z, i, p);
    es[i*2+1]=make_edge(i, z, 0);
  }
  REP(i, n){
    cin>>q;
    es[n*2+i*2]=make_edge(i+n, z, q);
    es[n*2+i*2+1]=make_edge(z, i+n, 0);
  }
  REP(i, m){
    cin>>x>>y>>a>>b;
    --x;
    --y;
    es[n*4+i*2]=make_edge(x, y+n, -a);
    es[n*4+i*2+1]=make_edge(y+n, x, b);
  }
  cout<<(find_negative_loop() ? "no" : "yes")<<'\n';
  return 0;
}
