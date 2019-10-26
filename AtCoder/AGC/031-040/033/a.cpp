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

int INF=1e9;
int h, w;
string s[1333];
int sy, sx, d[1333][1333], dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

int bfs(){
  queue<pair<pii, int>> q;
  REP(i, h){
    REP(j, w) d[i][j]=INF;
  }
  REP(i, h){
    REP(j, w){
      if(s[i][j]=='#'){
        q.push(make_pair(pii(i, j), 0));
        d[i][j]=0;
      }
    }
  }
  int res=0;
  while(q.size()){
    auto p=q.front();
    q.pop();
    REP(i, 4){
      int nx=p.first.first+dx[i];
      int ny=p.first.second+dy[i];
      if(nx>=0 && nx<h && ny>=0 && ny<w && s[nx][ny]!='#' && d[nx][ny]==INF){
        q.push(make_pair(pii(nx, ny), p.second+1));
        d[nx][ny]=d[p.first.first][p.first.second]+1;
        CHMAX(res, p.second+1);
        s[p.first.first][p.first.second]='#';
      }
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>h>>w;
  REP(i, h){
    cin>>s[i];
  }
  int ans=bfs();
  cout<<ans<<'\n';
  return 0;
}
