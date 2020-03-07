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

ll m[252521];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, p;
  string s;
  cin>>n>>p>>s;
  ll ans=0;
  if(p==2 || p==5){
    REP(i, n){
      int x=s[i]-'0';
      if(x%p==0){
        ans+=i+1;
      }
    }
    cout<<ans<<'\n';
    return 0;
  }
  int ten=1;
  FORR(i, 0, n){
    m[i]=(m[i+1]+ten*(s[i]-'0'))%p;
    ten=(ten*10)%p;
  }
  sort(m, m+n+1);
  ll l=0, r=0;
  while(l<n+1){
    while(r<n+1 && m[l]==m[r]){
      ++r;
    }
    ans+=(r-l)*(r-l-1)/2;
    l=r;
  }
  cout<<ans<<'\n';
  return 0;
}
