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

// constexpr ll MOD=1000000007ll;
constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int h, w;
  char s[12][12];
  cin>>h>>w;
  REP(i, h){
    REP(j, w){
      cin>>s[i][j];
    }
  }
  int sx, sy;
  [&]{
    REP(i, h){
      REP(j, w){
        if(s[i][j]=='#'){
          sx=i;
          sy=j;
          return;
        }
      }
    }
  }();
  int ans=1;
  int tx=sx+1, ty=sy;
  int cur=0;
  // DEBUG(sx);DEBUG(sy);
  while(tx!=sx || ty!=sy){
    // cout<<tx<<' '<<ty<<'\n';
    // DEBUG(cur);
    if(s[tx][ty-1]!=s[tx][ty]){
      if(cur!=2){
        if(cur!=0){
          ++ans;
        }
        cur=0;
        tx=tx+1;
        ty=ty;
        continue;
      }
    }
    if(s[tx][ty]!=s[tx-1][ty]){
      if(cur!=3){
        if(cur!=1){
          ++ans;
        }
        cur=1;
        tx=tx;
        ty=ty+1;
        continue;
      }
    }
    if(s[tx-1][ty-1]!=s[tx-1][ty]){
      if(cur!=0){
        if(cur!=2){
          ++ans;
        }
        cur=2;
        tx=tx-1;
        ty=ty;
        continue;
      }
    }
    if(cur!=3){
      ++ans;
    }
    cur=3;
    tx=tx;
    ty=ty-1;
  }
  cout<<ans<<'\n';
  return 0;
}
