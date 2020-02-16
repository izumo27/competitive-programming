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

// 繰り上がりなし、あり
int dp[1252521][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  string n;
  cin>>n;
  n="0"+n;
  int m=n.size();
  int ans=0;
  REP(i, m+1){
    dp[i][0]=dp[i][1]=INF;
  }
  dp[m][0]=0;
  FORR(i, 0, m){
    int x=n[i]-'0';
    if(dp[i+1][0]!=INF){
      CHMIN(dp[i][0], dp[i+1][0]+x);
      CHMIN(dp[i][1], dp[i+1][0]+10-x);
    }
    if(dp[i+1][1]!=INF){
      if(x==9){
        CHMIN(dp[i][1], dp[i+1][1]);
      }
      else{
        CHMIN(dp[i][0], dp[i+1][1]+x+1);
        CHMIN(dp[i][1], dp[i+1][1]+10-x-1);
      }
    }
  }
  // REP(i, m){
  //   REP(j, 2){
  //     cout<<dp[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }
  cout<<min(dp[0][0], dp[0][1])<<'\n';
  return 0;
}
