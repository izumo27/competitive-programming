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
  int h, w, K;
  cin>>h>>w>>K;
  char s[15][1252];
  REP(i, h){
    REP(j, w){
      cin>>s[i][j];
    }
  }
  int ans=1e9;
  REP(i, 1<<(h-1)){
    int cnt=0;
    vi v;
    v.push_back(0);
    REP(j, h-1){
      if(i>>j&1){
        ++cnt;
        v.push_back(j+1);
      }
    }
    v.push_back(h);
    int m=v.size();
    vi u(m-1);
    bool can=true;
    [&]{REP(k, w){
      bool ok=true;
      vi uu(m-1);
      REP(l, m-1){
        int sx=v[l], tx=v[l+1];
        int tmp=0;
        FOR(xx, sx, tx){
          if(s[xx][k]=='1'){
            ++tmp;
          }
        }
        if(tmp>K){
          can=false;
          return;
        }
        uu[l]=tmp;
        if(u[l]+uu[l]>K){
          ok=false;
        }
      }
      if(!ok){
        ++cnt;
        REP(l, m-1){
          u[l]=uu[l];
        }
      }
      else{
        REP(l, m-1){
          u[l]+=uu[l];
        }
      }
      // if(i==0){
      //   DEBUG_VEC(u);
      // }
    }
    }();
    if(can){
      CHMIN(ans, cnt);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
