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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m;
  ll a[114514];
  pll bc[114514];
  cin>>n>>m;
  REP(i, n){
    cin>>a[i];
  }
  sort(a, a+n);
  REP(i, m){
    cin>>bc[i].second>>bc[i].first;
  }
  sort(bc, bc+m);
  ll ans=0;
  int now=m-1;
  bool ok=false;
  REP(i, n){
    if(ok){
      ans+=a[i];
    }
    else{
      if(a[i]>=bc[now].first){
        ok=true;
        ans+=a[i];
        continue;
      }
      ans+=bc[now].first;
      --bc[now].second;
      if(bc[now].second==0){
        --now;
      }
      if(now<0){
        ok=true;
      }
    }
    // DEBUG(ans);
  }
  cout<<ans<<'\n';
  return 0;
}
