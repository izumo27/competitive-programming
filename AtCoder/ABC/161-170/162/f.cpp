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

ll dp[252521][3];
constexpr ll INF=1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  ll a[252521];
  cin>>n;
  REP(i, n){
    cin>>a[i];
  }
  int d=1+(n&1);
  REP(i, n+3){
    REP(j, d+1){
      dp[i][j]=-INF;
    }
  }
  dp[0][0]=0;
  REP(i, n+d){
    REP(j, d+1){
      if(i<n){
        CHMAX(dp[i+2][j], dp[i][j]+a[i]);
      }
      if(j<d){
        CHMAX(dp[i+1][j+1], dp[i][j]);
      }
    }
  }
  ll ans=-INF;
  REP(i, 3){
    CHMAX(ans, dp[n+i][d]);
  }
  cout<<ans<<'\n';
  return 0;
}
