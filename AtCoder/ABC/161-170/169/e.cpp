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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  ll a[252521], b[252521];
  cin>>n;
  REP(i, n){
    cin>>a[i]>>b[i];
  }
  // vi ord(n);
  // iota(ALL(ord), 0);
  // sort(ALL(ord), [&a, &b](int x, int y){
  //   if(a[x]==a[y]) return b[x]<b[y];
  //   return a[x]<a[y];
  // });
  sort(a, a+n);
  sort(b, b+n);
  if(n&1){
    cout<<b[n/2]-a[n/2]+1<<'\n';
  }
  else{
    ll mi=(a[n/2]+a[n/2-1]);
    ll ma=(b[n/2]+b[n/2-1]);
    cout<<ma-mi+1<<'\n';
  }
  return 0;
}
