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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, k;
  string s;
  cin>>n>>k>>s;
  int r=0;
  while(r<n && s[r]=='1'){
    ++r;
  }
  REP(i, k){
    while(r<n && s[r]=='0'){
      ++r;
    }
    while(r<n && s[r]=='1'){
      ++r;
    }
  }
  if(r==n){
    cout<<n<<'\n';
    return 0;
  }
  int ans=r, l=0;
  while(l<n){
    while(l<n && s[l]=='1'){
      ++l;
    }
    while(l<n && s[l]=='0'){
      ++l;
    }
    while(r<n && s[r]=='0'){
      ++r;
    }
    while(r<n && s[r]=='1'){
      ++r;
    }
    CHMAX(ans, r-l);
  }
  cout<<ans<<'\n';
  return 0;
}
