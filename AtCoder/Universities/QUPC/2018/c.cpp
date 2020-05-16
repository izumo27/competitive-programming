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

#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

#define CHMIN(a, b) a=min((a), (b))
#define CHMAX(a, b) a=max((a), (b))

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const int INF=1e9;

int h, w, x;
char s[1333][1333];
bool used[1333][1333];

int sx, sy, gx, gy, d[1333][1333], dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
vi ix, iy;

void bfs(){
  queue<pii> q;
  REP(i, h){
    REP(j, w){
      d[i][j]=INF;
    }
  }
  REP(i, ix.size()){
    q.push(pii(ix[i], iy[i]));
    d[ix[i]][iy[i]]=0;
    used[ix[i]][iy[i]]=true;
  }
  while(q.size()){
    pii p=q.front();
    q.pop();
    if(d[p.first][p.second]>=x){
      continue;
    }
    REP(i, 4){
      int nx=p.first+dx[i];
      int ny=p.second+dy[i];
      if(nx>=0 && nx<h && ny>=0 && ny<w && s[nx][ny]!='#' && d[nx][ny]==INF){
        q.push(pii(nx, ny));
        d[nx][ny]=d[p.first][p.second]+1;
        used[nx][ny]=true;
      }
    }
  }
  return;
}

void bfs2(){
  queue<pii> q;
  REP(i, h){
    REP(j, w){
      d[i][j]=INF;
    }
  }
  q.push(pii(sx, sy));
  d[sx][sy]=0;
  while(q.size()){
    pii p=q.front();
    q.pop();
    if(p.first==gx && p.second==gy){
      return;
    }
    REP(i, 4){
      int nx=p.first+dx[i];
      int ny=p.second+dy[i];
      if(nx>=0 && nx<h && ny>=0 && ny<w && s[nx][ny]!='#' && !used[nx][ny] && d[nx][ny]==INF){
        q.push(pii(nx, ny));
        d[nx][ny]=d[p.first][p.second]+1;
      }
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>h>>w>>x;
  REP(i, h){
    REP(j, w){
      cin>>s[i][j];
      if(s[i][j]=='S'){
        sx=i;
        sy=j;
      }
      if(s[i][j]=='G'){
        gx=i;
        gy=j;
      }
      if(s[i][j]=='@'){
        ix.push_back(i);
        iy.push_back(j);
      }
    }
  }
  bfs();
  bfs2();
  cout<<(d[gx][gy]!=INF ? d[gx][gy] : -1)<<'\n';
  return 0;
}
