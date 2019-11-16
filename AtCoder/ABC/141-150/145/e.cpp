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

constexpr int INF=1e9;

int dp[3252][3252];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, t, a[3252], b[3252], c[3252], d[3252];
  cin>>n>>t;
  REP(i, n){
    cin>>c[i]>>d[i];
  }
  vi ord(n);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&c, &d](int x, int y){
    if(c[x]==c[y]) return d[x]<d[y];
    return c[x]<c[y];
  });
  REP(i, n){
    a[i]=c[ord[i]];
    b[i]=d[ord[i]];
  }
  REP(i, n+1){
    REP(j, t+1){
      dp[i][j]=INF;
    }
  }
  dp[0][0]=0;
  int ans=0;
  REP(i, n){
    REP(j, t+1){
      if(dp[i][j]==INF){
        continue;
      }
      if(dp[i+1][j]==INF){
        dp[i+1][j]=dp[i][j];
      }
      else{
        CHMAX(dp[i+1][j], dp[i][j]);
      }
      CHMAX(ans, dp[i][j]+b[i]);
      if(j+a[i]<t){
        if(dp[i+1][j+a[i]]==INF){
          dp[i+1][j+a[i]]=dp[i][j]+b[i];
        }
        else{
          CHMAX(dp[i+1][j+a[i]], dp[i][j]+b[i]);
        }
        // CHMAX(ans, dp[i+1][j+a[i]]);
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
