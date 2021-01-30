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

constexpr int INF=1e9;

int n, m, a[125252], b[125252], k, c[25];

vi g[125252];
int dis[25][125252];
int mp[125252];
ll dp[1<<17][25];
int start;

ll rec(int S, int v){
  if(dp[S][v]>=0){
    return dp[S][v];
  }
  if(S==(1<<k)-1){
    return dp[S][start]=0;
  }
  ll res=INF;
  REP(u, k){
    if(!(S>>u&1)){
      CHMIN(res, rec(S|1<<u, u)+dis[v][c[u]]);
    }
  }
  return dp[S][v]=res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n>>m;
  REP(i, m){
    cin>>a[i]>>b[i];
    --a[i];--b[i];
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  cin>>k;
  REP(i, k){
    cin>>c[i];
    --c[i];
    mp[c[i]]=i;
  }
  REP(i, k){
    REP(j, n){
      dis[i][j]=INF;
    }
    dis[i][c[i]]=0;
    queue<pii> que;
    que.push(pii(c[i], 0));
    while(!que.empty()){
      auto [s, d]=que.front();que.pop();
      for(auto& v : g[s]){
        if(d+1<dis[i][v]){
          dis[i][v]=d+1;
          que.push(pii(v, d+1));
        }
      }
    }
  }
  ll ans=INF;
  REP(i, k){
    REP(j, 1<<k){
      REP(l, k){
        dp[j][l]=-1;
      }
    }
    start=i;
    ll res=rec(1<<i, i);
    CHMIN(ans, res);
  }
  cout<<(ans==INF ? -1 : ans+1)<<'\n';
  return 0;
}
