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

constexpr ll INF=1e18;

int n;
ll xy[2][20], p[20];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n;
  REP(i, n){
    cin>>xy[0][i]>>xy[1][i]>>p[i];
  }
  ll d[2][(1<<n)+1][n];
  REP(i, 1<<n){
    REP(j, n){
      REP(k, 2){
        d[k][i][j]=abs(xy[k][j]);
      }
      REP(k, n){
        if(i>>k&1){
          REP(l, 2){
            CHMIN(d[l][i][j], abs(xy[l][k]-xy[l][j]));
          }
        }
      }
    }
  }
  ll ans[n+1];
  REP(i, n+1){
    ans[i]=INF;
  }
  REP(i, 1<<n){
    int cnt=0;
    REP(j, n){
      if(i>>j&1){
        ++cnt;
      }
    }
    int j=i;
    do{
      // ここに処理を書く
      ll tmp=0;
      REP(l, n){
        if(!(i>>l&1)){
          tmp+=min(d[0][j][l], d[1][i-j][l])*p[l];
        }
      }
      CHMIN(ans[cnt], tmp);
      j=(j-1)&i;
    }while(j!=i);
  }
  REP(i, n+1){
    cout<<ans[i]<<'\n';
  }
  return 0;
}
