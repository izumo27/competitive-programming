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

vi g[125252];
int dv[125252], du[125252];
constexpr int INF=1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, u, v;
  cin>>n>>u>>v;
  --u;--v;
  REP(i, n-1){
    int a, b;
    cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  REP(i, n){
    dv[i]=INF;
  }
  queue<int> q;
  q.push(v);
  dv[v]=0;
  while(q.size()){
    int s=q.front();q.pop();
    for(auto& x : g[s]){
      if(dv[x]!=INF){
        continue;
      }
      dv[x]=dv[s]+1;
      q.push(x);
    }
  }
  // REP(i, n){
  //   cout<<dv[i]<<" \n"[i==n-1];
  // }
  REP(i, n){
    du[i]=INF;
  }
  queue<int> q2;
  q2.push(u);
  du[u]=0;
  int ans=dv[u];
  while(q2.size()){
    int s=q2.front();q2.pop();
    for(auto& x : g[s]){
      // DEBUG(x);
      // DEBUG(du[x]);DEBUG(du[s]);DEBUG(dv[x]);
      if(du[x]!=INF || du[s]+1>=dv[x]){
        continue;
      }
      du[x]=du[s]+1;
      q2.push(x);
      CHMAX(ans, dv[x]);
    }
  }
  // REP(i, n){
  //   cout<<du[i]<<" \n"[i==n-1];
  // }
  --ans;
  cout<<ans<<'\n';
  return 0;
}
