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

int ans[334][334];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int h, w, k;
  char s[334][334];
  cin>>h>>w>>k;
  int cnt=0;
  REP(i, h)REP(j, w){
    cin>>s[i][j];
    if(s[i][j]=='#'){
      ans[i][j]=++cnt;
    }
  }
  REP(i, h)REP(j, w){
    if(s[i][j]=='#'){
      FORR(y, 0, j){
        if(ans[i][y]){
          break;
        }
        ans[i][y]=ans[i][j];
      }
      FOR(y, j+1, w){
        if(ans[i][y]){
          break;
        }
        ans[i][y]=ans[i][j];
      }
    }
  }
  REP(i, h)REP(j, w){
    if(ans[i][j]){
      continue;
    }
    FOR(x, i+1, h){
      if(ans[x][j]){
        ans[i][j]=ans[x][j];
        break;
      }
    }
    if(ans[i][j]){
      continue;
    }
    FORR(x, 0, i){
      if(ans[x][j]){
        ans[i][j]=ans[x][j];
        break;
      }
    }
  }
  REP(i, h){
    REP(j, w){
      cout<<ans[i][j]<<" \n"[j==w-1];
    }
  }
  return 0;
}
