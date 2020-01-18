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

bool ng[125252];
ll dp[2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  ll x[125252], l[125252];
  cin>>n;
  REP(i, n){
    cin>>x[i]>>l[i];
  }
  vi ord(n);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&x, &l](int a, int b){
    return x[a]<x[b];
  });
  int ans=1;
  dp[0]=-1e10;
  dp[1]=x[ord[0]]+l[ord[0]];
  FOR(i, 1, n){
    if(dp[1]<=x[ord[i]]-l[ord[i]]){
      ++ans;
      dp[0]=dp[1];
      dp[1]=x[ord[i]]+l[ord[i]];
    }
    else if(dp[0]<=x[ord[i]]-l[ord[i]]){
      CHMIN(dp[1], x[ord[i]]+l[ord[i]]);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
