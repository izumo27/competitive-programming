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
  string s;
  ll k;
  cin>>s>>k;
  int n=s.size();
  if(n==1){
    ll ans=k/2;
    cout<<ans<<'\n';
    return 0;
  }
  int cnt=0;
  REP(i, n-1){
    if(s[i]==s[i+1]){
      ++i;
      ++cnt;
    }
  }
  int a=n-1;
  REP(i, n-1){
    if(s[i]!=s[i+1]){
      a=i;
      break;
    }
  }
  int b=-1;
  FORR(i, 0, n-1){
    if(s[i]!=s[i+1]){
      b=i;
      break;
    }
  }
  ++a;
  b=n-b-1;
  // DEBUG(a);
  // DEBUG(b);
  if(a==n){
    if(a>1 && a&1){
      ll ans=(cnt*2+1)*k/2;
      cout<<ans<<'\n';
      return 0;
    }
  }
  ll ans=cnt*k;
  if(s[0]==s[n-1] && a>1 && b>1 && a&1 && b&1){
    ans+=k-1;
  }
  cout<<ans<<'\n';
  return 0;
}
