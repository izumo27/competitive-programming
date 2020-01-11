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

template<typename T> T gcd(T a, T b){
  if(b==0){
    return a;
  }
  return gcd(b, a%b);
}

template<typename T> T lcm(T a, T b){
  return a/gcd(a, b)*b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  ll m, a[125252];
  cin>>n>>m;
  REP(i, n){
    cin>>a[i];
  }
  ll cur=1;
  REP(i, n){
    cur=lcm(cur, a[i]/2);
    if(cur>m){
      cout<<0<<'\n';
      return 0;
    }
  }
  int num=1;
  ll b=cur;
  while(b%2==0){
    b/=2;
    ++num;
  }
  REP(i, n){
    int tmp=0;
    while(a[i]%2==0){
      a[i]/=2;
      ++tmp;
    }
    if(num!=tmp){
      cout<<0<<'\n';
      return 0;
    }
  }
  m-=cur;
  ll ans=m/(cur*2)+1;
  cout<<ans<<'\n';
  return 0;
}
