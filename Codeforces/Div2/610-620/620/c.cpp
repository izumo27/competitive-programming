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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int q;
  cin>>q;
  while(q--){
    ll n, m;
    cin>>n>>m;
    bool ok=true;
    ll cur=0, lb=m, ub=m;
    REP(i, n){
      ll t, l, h;
      cin>>t>>l>>h;
      lb-=(t-cur);
      ub+=(t-cur);
      if(ub<l || h<lb){
        ok=false;
      }
      CHMAX(lb, l);
      CHMIN(ub, h);
      cur=t;
    }
    cout<<(ok ? "YES" : "NO")<<'\n';
  }
  return 0;
}
