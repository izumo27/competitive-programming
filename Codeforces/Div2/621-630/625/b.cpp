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
  int n, b[252521];
  cin>>n;
  pii c[252521];
  REP(i, n){
    cin>>b[i];
    b[i]-=i;
    c[i]=pii(b[i], i);
  }
  sort(c, c+n);
  ll ans=0;
  int idx=0;
  while(idx<n){
    ll tmp=c[idx].first+c[idx].second;
    while(idx<n-1 && c[idx].first==c[idx+1].first){
      tmp+=c[idx+1].first+c[idx+1].second;
      ++idx;
    }
    CHMAX(ans, tmp);
    // DEBUG(c[idx].first);
    // DEBUG(ans);
    ++idx;
  }
  cout<<ans<<'\n';
  return 0;
}
