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
  ll n;
  cin>>n;
  int cnt=0;
  ll m=n;
  while(m>0){
    cnt+=m%10;
    m/=10;
  }
  ll ans=cnt%9;
  REP(i, cnt/9){
    ans*=10;
    ans+=9;
  }
  if(ans!=n){
    cout<<ans<<'\n';
    return 0;
  }
  if(cnt%9==0 || cnt/9==0){
    cout<<1;
    ll tmp=1;
    REP(i, cnt/9){
      tmp*=10;
    }
    if(cnt%9==0){
      tmp/=10;
    }
    cout<<ans-tmp<<'\n';
  }
  else{
    ll tmp=1;
    REP(i, cnt/9){
      tmp*=10;
    }
    ans+=tmp;
    ans-=tmp/10;
    cout<<ans<<'\n';
  }
  return 0;
}
