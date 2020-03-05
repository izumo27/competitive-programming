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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  string s;
  cin>>n>>s;
  int ans=0;
  for(char c='z'; c>'a'; --c){
    int i=0;
    while(i<n){
      bool ok=false;
      if((s[i]==c)){
        if((i>0 && s[i-1]==c-1) || (i<n-1 && s[i+1]==c-1)){
          s.erase(i, 1);
          ++ans;
          --n;
          ok=true;
        }
      }
      if(ok){
        i=0;
      }
      else{
        ++i;
      }
      // DEBUG(i);
      // DEBUG(s);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
