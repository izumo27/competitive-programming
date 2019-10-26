#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORR(i, a, b) for(int i=b-1; i>=a; --i)

const int INF=1<<20;
int h, w, n, sx, sy, ans, d[1100][1100], dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
char maze[1100][1100];
pii f[20];

void bfs(pii f1, pii f2){
  queue<pii> q;
  REP(i, h){
    REP(j, w) d[i][j]=INF;
  }
  q.push(f1);
  d[f1.first][f1.second]=0;
  while(q.size()){
    pii p=q.front();
    q.pop();
    if(p.first==f2.first && p.second==f2.second){
      ans+=d[f2.first][f2.second];
      return;
    }
    REP(i, 4){
      int fx=p.first+dx[i];
      int fy=p.second+dy[i];
      if(fx>=0 && fx<h && fy>=0 && fy<w && maze[fx][fy]!='X' && d[fx][fy]==INF){
        q.push(pii(fx, fy));
        d[fx][fy]=d[p.first][p.second]+1;
      }
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>h>>w>>n;
  int count=0;
  REP(i, h){
    REP(j, w){
      cin>>maze[i][j];
      if(maze[i][j]=='S'){
        sx=i;
        sy=j;
        continue;
      }
      if(maze[i][j]>='1' && maze[i][j]<='9'){
        f[maze[i][j]-'0']=pii(i, j);
        ++count;
        continue;
      }
    }
  }
  f[0]=pii(sx, sy);
  REP(i, count) bfs(f[i], f[i+1]);
  cout<<ans<<'\n';
  return 0;
}
