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

// 立っているビット数を求める (int)
inline int bit_count(int n){
  n=((n>>1)&0x55555555)+(n&0x55555555);
  n=((n>>2)&0x33333333)+(n&0x33333333);
  n=((n>>4)&0x0f0f0f0f)+(n&0x0f0f0f0f);
  n=((n>>8)&0x00ff00ff)+(n&0x00ff00ff);
  n=((n>>16)&0x0000ffff)+(n&0x0000ffff);
  return n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[20], x[20][20], y[20][20];
  cin>>n;
  REP(i, n){
    cin>>a[i];
    REP(j, a[i]){
      cin>>x[i][j]>>y[i][j];
      --x[i][j];
    }
  }
  int ans=0;
  REP(i, 1<<n){
    int num[20];
    REP(j, n){
      num[j]=-1;
    }
    bool ok=true;
    REP(j, n){
      if(i>>j&1){
        REP(k, a[j]){
          if(i>>x[j][k]&1){
            if(!y[j][k]){
              ok=false;
            }
          }
          else{
            if(y[j][k]){
              ok=false;
            }
          }
          if(num[x[j][k]]==-1){
            num[x[j][k]]=y[j][k];
          }
          else if(num[x[j][k]]!=y[j][k]){
            ok=false;
          }
        }
      }
    }
    if(ok){
      CHMAX(ans, bit_count(i));
    }
  }
  cout<<ans<<'\n';
  return 0;
}