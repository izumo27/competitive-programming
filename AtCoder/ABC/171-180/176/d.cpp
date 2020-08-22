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
int d[1252][1252];
int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int h, w, cx, cy, gx, gy;
  char s[1252][1252];
  cin>>h>>w>>cx>>cy>>gx>>gy;
  --cx;--cy;--gx;--gy;
  REP(i, h){
    REP(j, w){
      cin>>s[i][j];
    }
  }
  REP(i, h){
    REP(j, w){
      d[i][j]=INF;
    }
  }
  d[cx][cy]=0;
  deque<pair<pii, int>> que;
  que.push_front(make_pair(pii(cx, cy), 0));
  while(que.size()){
    auto xyd=que.front();que.pop_front();
    auto xy=xyd.first;
    int sx=xy.first, sy=xy.second, sd=xyd.second;
    REP(i, 4){
      int tx=sx+dx[i], ty=sy+dy[i];
      if(tx<0 || tx>=h || ty<0 || ty>=w || s[tx][ty]=='#'){
        continue;
      }
      if(d[tx][ty]<=sd){
        continue;
      }
      d[tx][ty]=sd;
      que.push_front(make_pair(pii(tx, ty), sd));
    }
    FOR(i, -2, 3){
      FOR(j, -2, 3){
        int tx=sx+i, ty=sy+j;
        if(tx<0 || tx>=h || ty<0 || ty>=w || s[tx][ty]=='#'){
          continue;
        }
        if(d[tx][ty]<=sd+1){
          continue;
        }
        d[tx][ty]=sd+1;
        que.push_back(make_pair(pii(tx, ty), sd+1));
      }
    }
  }
  // REP(i, h){
  //   REP(j, w){
  //     cout<<d[i][j]<<" \n"[j==w-1];
  //   }
  // }
  cout<<(d[gx][gy]==INF ? -1 : d[gx][gy])<<'\n';
  return 0;
}
