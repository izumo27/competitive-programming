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
int dp[125252][20];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m, Q, a, b, v[125252], d[125252], c[125252];
  cin>>n>>m;
  REP(i, m){
    cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin>>Q;
  REP(i, Q){
    cin>>v[i]>>d[i]>>c[i];
    --v[i];
  }
  FORR(i, 0, Q){
    // 頂点、距離、色
    queue<pii> q;
    q.emplace(v[i], d[i]);
    while(q.size()){
      auto x=q.front();
      q.pop();
      int vv=x.first, dd=x.second;
      if(dp[vv][dd]) continue;
      dp[vv][dd]=c[i];
      FORR(j, 0, dd){
        if(dp[vv][j]) break;
        dp[vv][j]=c[i];
      }
      if(!dd) continue;
      for(auto y : g[vv]){
        q.emplace(y, dd-1);
      }
    }
  }
  // REP(i, n){
  //   REP(j, 3){
  //     cout<<dp[i][j]<<" \n"[j==1];
  //   }
  // }
  REP(i, n){
    cout<<dp[i][0]<<'\n';
  }
  return 0;
}
