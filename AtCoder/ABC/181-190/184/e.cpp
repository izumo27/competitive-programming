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
vector<pii> alps[30];
int d[2525][2525];
bool used[30];
int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int h, w;
  char a[2525][2525];
  cin>>h>>w;
  int sx, sy, gx, gy;
  REP(i, h){
    REP(j, w){
      cin>>a[i][j];
      if(a[i][j]=='S'){
        sx=i;sy=j;
      }
      if(a[i][j]=='G'){
        gx=i;gy=j;
      }
      if('a'<=a[i][j] && a[i][j]<='z'){
        alps[a[i][j]-'a'].push_back(pii(i, j));
      }
    }
  }
  REP(i, h){
    REP(j, w){
      d[i][j]=INF;
    }
  }
  queue<pii> que;
  que.push(pii(sx, sy));
  d[sx][sy]=0;
  while(!que.empty()){
    auto [x, y]=que.front();que.pop();
    if(x==gx && y==gy){
      break;
    }
    REP(i, 4){
      int tx=x+dx[i], ty=y+dy[i];
      if(tx<0 || tx>=h || ty<0 || ty>=w){
        continue;
      }
      if(a[tx][ty]=='#' || d[tx][ty]!=INF){
        continue;
      }
      d[tx][ty]=d[x][y]+1;
      que.push(pii(tx, ty));
    }
    if('a'<=a[x][y] && a[x][y]<='z'){
      if(!used[a[x][y]-'a']){
        used[a[x][y]-'a']=true;
        for(auto& alp : alps[a[x][y]-'a']){
          auto [tx, ty]=alp;
          if(d[tx][ty]<=d[x][y]+1){
            continue;
          }
          d[tx][ty]=d[x][y]+1;
          que.push(pii(tx, ty));
        }
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
