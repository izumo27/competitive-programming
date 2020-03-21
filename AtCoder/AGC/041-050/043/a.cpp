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

constexpr int INF=1e9;
int h, w;
char s[125][125];
int d[125][125];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>h>>w;
  REP(i, h){
    REP(j, w){
      cin>>s[i][j];
      d[i][j]=INF;
    }
  }
  d[0][0]=(s[0][0]=='.' ? 0 : 1);
  REP(x, h){
    REP(y, w){
      if(x+1<h){
        int tx=x+1, ty=y;
        int tmp=(s[tx][ty]=='#' && s[tx][ty]!=s[x][y] ? d[x][y]+1 : d[x][y]);
        CHMIN(d[tx][ty], tmp);
      }
      if(y+1<w){
        int tx=x, ty=y+1;
        int tmp=(s[tx][ty]=='#' && s[tx][ty]!=s[x][y] ? d[x][y]+1 : d[x][y]);
        CHMIN(d[tx][ty], tmp);
      }
    }
  }
  // REP(i, h){
  //   REP(j, w){
  //     cout<<d[i][j]<<" \n"[j==w-1];
  //   }
  // }
  cout<<d[h-1][w-1]<<'\n';
  return 0;
}
