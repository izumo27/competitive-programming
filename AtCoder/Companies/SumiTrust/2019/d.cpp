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

bool dp[20][20][20];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  string s;
  cin>>n>>s;
  dp[0][0][0]=true;
  REP(i, n){
    int tmp=s[i]-'0'+1;
    FORR(y, 0, 11){
      FORR(x, 0, 11){
        if(!dp[x][y][0]){
          continue;
        }
        if(y>0){
          if(dp[x][y][0]){
            dp[x][y][tmp]=true;
          }
        }
        else{
          if(x>0){
            dp[x][tmp][0]=true;
          }
          else{
            dp[tmp][0][0]=true;
          }
        }
      }
    }
  }
  int ans=0;
  FOR(x, 1, 11){
    FOR(y, 1, 11){
      FOR(z, 1, 11){
        if(dp[x][y][z]){
          // cout<<x-1<<' '<<y-1<<' '<<z-1<<'\n';
          ++ans;
        }
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}