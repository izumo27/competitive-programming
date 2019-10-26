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
  int n, m, k[20], s[20][20], p[20];
  cin>>n>>m;
  REP(i, m){
    cin>>k[i];
    REP(j, k[i]){
      cin>>s[i][j];
      --s[i][j];
    }
  }
  REP(i, m){
    cin>>p[i];
  }
  int on[20];
  int ans=0;
  REP(i, 1<<n){
    REP(j, n){
      on[j]=0;
    }
    REP(j, n){
      if((i>>j)&1){
        on[j]=1;
      }
    }
    bool ok=true;
    REP(j, m){
      int cnt=0;
      REP(j2, k[j]){
        if(on[s[j][j2]]){
          // DEBUG(j2);
          // DEBUG(cnt);
          ++cnt;
        }
      }
      // DEBUG(i);
      // DEBUG(cnt);
      if((cnt&1)!=p[j]){
        ok=false;
        break;
      }
    }
    if(ok){
      ++ans;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
