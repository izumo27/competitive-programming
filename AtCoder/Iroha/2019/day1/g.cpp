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

ll dp[2][400][400];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m, k;
  ll a[400];
  cin>>n>>m>>k;
  REP(i, n){
    cin>>a[i];
  }
  REP(x, 2){
    REP(y, m+1){
      REP(z, k+1){
        dp[x][y][z]=-1;
      }
    }
  }
  dp[0][0][0]=0;
  REP(x, n){
    REP(y, m+1){
      REP(z, k){
        dp[(x+1)&1][y][z]=-1;
      }
    }
    REP(y, m+1){
      REP(z, k){
        if(dp[x&1][y][z]<0){
          continue;
        }
        if(z!=k-1){
          CHMAX(dp[(x+1)&1][y][z+1], dp[x&1][y][z]);
          // DEBUG(dp[x&1][y][z]);
        }
        if(y!=m){
          CHMAX(dp[(x+1)&1][y+1][0], dp[x&1][y][z]+a[x]);
          // DEBUG(dp[(x+1)&1][y+1][0]);
        }
      }
    }
  }
  ll ans=-1;
  REP(z, k){
    CHMAX(ans, dp[n&1][m][z]);
  }
  cout<<ans<<'\n';
  return 0;
}
