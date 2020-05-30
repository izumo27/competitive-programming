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

constexpr ll INF=(1ll<<60);
ll ma[125252];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  ll a[125252];
  cin>>n;
  REP(i, n+1){
    cin>>a[i];
  }
  ma[0]=1;
  FOR(i, 1, n+1){
    if(ma[i-1]<a[i-1]){
      cout<<-1<<'\n';
      return 0;
    }
    ll tmp=ma[i-1]-a[i-1];
    CHMIN(tmp, INF/2);
    ma[i]=tmp*2;
  }
  ll ans=0;
  bool ok=true;
  ll cur=0;
  FORR(i, 0, n+1){
    if((cur+1)/2+a[i]>ma[i]){
      cout<<-1<<'\n';
      return 0;
    }
    cur=min(ma[i], cur+a[i]);
    ans+=cur;
  }
  cout<<(ok ? ans : -1)<<'\n';
  return 0;
}
