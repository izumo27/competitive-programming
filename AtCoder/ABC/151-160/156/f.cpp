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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int k, q;
  ll d[5252];
  cin>>k>>q;
  REP(i, k){
    cin>>d[i];
  }
  while(q--){
    ll n, x, m;
    cin>>n>>x>>m;
    --n;
    x%=m;
    ll b[5252];
    ll sum=0;
    int zero=0;
    REP(i, k){
      b[i]=d[i]%m;
      sum+=b[i];
      zero+=(b[i]==0);
    }
    ll cnt=(x+sum*(n/k))/m;
    // DEBUG(cnt);
    ll ans=n/k*k-(cnt+zero*(n/k));
    // DEBUG(ans);
    ll cur=(x+sum%m*(n/k))%m;
    REP(i, n%k){
      ll tmp=(cur+b[i])%m;
      // DEBUG(cur);
      // DEBUG(tmp);
      if(cur<tmp){
        ++ans;
      }
      cur=tmp;
    }
    cout<<ans<<'\n';
  }
  return 0;
}
