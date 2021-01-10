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

vi g[252521];
ll dp[252521];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m;
  ll a[252521];
  cin>>n>>m;
  REP(i, n){
    cin>>a[i];
  }
  REP(i, m){
    int x, y;
    cin>>x>>y;
    --x;--y;
    g[x].push_back(y);
  }
  ll ans=-1e18;
  FORR(i, 0, n-1){
    for(auto& u : g[i]){
      CHMAX(dp[i], dp[u]);
      CHMAX(dp[i], a[u]);
    }
    if(dp[i]!=0){
      CHMAX(ans, dp[i]-a[i]);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
