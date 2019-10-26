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

int num[60];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  ll a;
  int k;
  cin>>a>>k;
  ll b=a;
  int cnt=0;
  while(b){
    num[cnt++]=b%10;
    b/=10;
  }
  ll ans=1e18, mask=1;
  REP(i, cnt+2){
    ll t=a/mask*mask;
    mask*=10;
    bool x[10];
    REP(j, 10) x[j]=false;
    FORR(j, i, cnt){
      x[num[j]]=true;
    }
    int y=0;
    REP(j, 10) if(x[j]) ++y;
    if(y>k) continue;
    REP(j, 10){
      int z=y;
      if(t){
        if(!x[j]) ++z;
      }
      else{
        if(!x[j] && j) ++z;
      }
      if(z>k) continue;
      REP(l, 10){
        if(z==k && l!=j && !x[l]) continue;
        ll s=j;
        FORR(k, 0, i-1){
          s*=10;
          s+=l;
        }
        CHMIN(ans, abs(s+t-a));
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
