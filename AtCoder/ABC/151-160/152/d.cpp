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

ll cnt[20][20];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  cin>>n;
  FOR(i, 1, n+1){
    int m=i;
    int x=m%10, y=m%10;
    while(m>0){
      y=m%10;
      m/=10;
    }
    ++cnt[y][x];
  }
  // FOR(i, 1, 10){
  //   FOR(j, 1, 10){
  //     cout<<cnt[i][j]<<" \n"[j==9];
  //   }
  // }
  ll ans=0;
  FOR(i, 1, 10){
    FOR(j, i, 10){
      if(i==j){
        ans+=cnt[i][i]*cnt[i][i];
        // if(cnt[i][i]*cnt[i][i]>0){
        //   DEBUG(i);DEBUG(j);
        // }
      }
      else{
        ans+=cnt[i][j]*cnt[j][i]*2;
        // if(cnt[j][i]*cnt[i][j]>0){
        //   DEBUG(i);DEBUG(j);
        // }
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
