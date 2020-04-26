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

const double EPS=1e-9;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

constexpr ll INF=1e18;
struct edge{
  int to;
  ll cost;
  ll time;
};

vector<edge> g[60];
ll dis[60][2525];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m;
  ll s;
  cin>>n>>m>>s;
  if(s>2500){
    s=2500;
  }
  REP(i, m){
    int u, v;
    ll a, b;
    cin>>u>>v>>a>>b;
    --u;--v;
    g[u].push_back({v, a, b});
    g[v].push_back({u, a, b});
  }
  REP(i, n){
    ll c, d;
    cin>>c>>d;
    g[i].push_back({i, -c, d});
  }
  REP(i, n){
    REP(j, 2501){
      dis[i][j]=INF;
    }
  }
  priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> que;
  que.push(make_pair(0ll, pll(0, s)));
  while(que.size()){
    auto zxy=que.top();que.pop();
    ll z=zxy.first;
    auto xy=zxy.second;
    ll x=xy.first, y=xy.second;
    ll tmp=dis[x][y];
    if(z>=tmp){
      continue;
    }
    // DEBUG(x);
    dis[x][y]=z;
    for(auto u : g[x]){
      if(y-u.cost<0){
        continue;
      }
      if(dis[u.to][y-u.cost]<=z+u.time){
        continue;
      }
      que.push(make_pair(z+u.time, pll(u.to, min(y-u.cost, 2500ll))));
    }
  }
  FOR(i, 1, n){
    ll mi=INF;
    REP(j, 2500){
      CHMIN(mi, dis[i][j]);
    }
    cout<<mi<<'\n';
  }
  return 0;
}
