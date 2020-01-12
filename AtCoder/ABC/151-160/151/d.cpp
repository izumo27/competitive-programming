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

int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int h, w;
  cin>>h>>w;
  char s[30][30];
  REP(i, w+2){
    s[0][i]=s[h+1][i]='#';
  }
  REP(i, h+2){
    s[i][0]=s[i][w+1]='#';
  }
  REP(i, h){
    REP(j, w){
      cin>>s[i+1][j+1];
    }
  }
  int ans=0;
  FOR(x, 1, h+1){
    FOR(y, 1, w+1){
      if(s[x][y]=='#'){
        continue;
      }
      FOR(a, 1, h+1){
        FOR(b, 1, w+1){
          if(s[a][b]=='#'){
            continue;
          }
          bool used[30][30];
          int d[30][30];
          FOR(i, 1, h+1){
            FOR(j, 1, w+1){
              used[i][j]=false;
            }
          }
          used[x][y]=true;
          d[x][y]=0;
          queue<pii> que;
          que.push(pii(x, y));
          while(que.size()){
            pii uv=que.front();que.pop();
            int u=uv.first, v=uv.second;
            if(u==a && v==b){
              break;
            }
            REP(i, 4){
              int uu=u+dx[i], vv=v+dy[i];
              if(s[uu][vv]=='#' || used[uu][vv]){
                continue;
              }
              used[uu][vv]=true;
              que.push(pii(uu, vv));
              d[uu][vv]=d[u][v]+1;
            }
          }
          CHMAX(ans, d[a][b]);
        }
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
