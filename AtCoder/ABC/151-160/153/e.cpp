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
int dp[12525];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int h, n, a[12525], b[12525];
  cin>>h>>n;
  double c[12525], d[12525];
  REP(i, n){
    cin>>a[i]>>b[i];
    c[i]=a[i];
    d[i]=b[i];
  }
  // vi ord(n);
  // iota(ALL(ord), 0);
  // sort(ALL(ord), [&c, &d](int x, int y){
  //   if(c[x]/d[x]==c[y]/d[y]){
  //     return d[x]<d[y];
  //   }
  //   return c[x]/d[x]<c[y]/d[y];
  // });
  REP(i, h+1){
    dp[i]=INF;
  }
  dp[0]=0;
  REP(i, h+1){
    if(dp[i]==INF){
      continue;
    }
    REP(j, n){
      if(i+a[j]>=h){
        CHMIN(dp[h], dp[i]+b[j]);
      }
      else{
        CHMIN(dp[i+a[j]], dp[i]+b[j]);
      }
    }
  }
  cout<<dp[h]<<'\n';
  return 0;
}
