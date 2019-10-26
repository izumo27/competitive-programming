#include <bits/stdc++.h>
#include <sys/time.h>

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

// 時刻取得（ミリ秒）
ull current_time_mills(){
  struct timeval _time;
  gettimeofday(&_time, NULL);
  return _time.tv_sec*1000+_time.tv_usec/1000;
}

// 乱数
unsigned int xor32(){
  static unsigned int x=2463534242;
  x=x^(x<<13);x=x^(x>>17);
  return x=x^(x<<15);
}

int n, m, a[60][60], a_sub[60][60];
int score;
int ans[2525][3], ans_sub[2525][3];
int dx[4]={0, -1, 0, 1}, dy[4]={-1, 0, 1, 0};
bool used[60][60];

int bfs(int sx, int sy, int thre){
  int res=1;
  queue<pii> q;
  REP(i, n){
    REP(j, n){
      used[i][j]=false;
    }
  }
  q.push(pii(sx, sy));
  used[sx][sy]=true;
  int cnt=thre-a[sx][sy];
  REP(i, cnt){
    ans_sub[i][0]=1;
    ans_sub[i][1]=sx;
    ans_sub[i][2]=sy;
  }
  while(q.size() && cnt<m-1){
    pii p=q.front();
    q.pop();
    REP(i, 4){
      int nx=p.first+dx[i];
      int ny=p.second+dy[i];
      if(nx>=0 && nx<n && ny>=0 && ny<n && !used[nx][ny] && a[nx][ny]<=thre){
        if(cnt+thre-a[nx][ny]>=m-1){
          FOR(i, cnt, m){
            ans_sub[i][0]=2;
            ans_sub[i][1]=sx;
            ans_sub[i][2]=sy;
          }
          cnt=m;
          break;
        }
        int tmp=thre-a[nx][ny];
        FOR(i, cnt, cnt+tmp){
          ans_sub[i][0]=1;
          ans_sub[i][1]=nx;
          ans_sub[i][2]=ny;
        }
        cnt+=tmp;
        ++res;
        q.push(pii(nx, ny));
        used[nx][ny]=true;
      }
    }
  }
  return res;
}

void dfs(int sx, int sy, int thre){
  REP(i, 4){
    int tx=sx+dx[i], ty=sy+dy[i];
    if(0<=tx && tx<n && 0<=ty && ty<n && a_sub[tx][ty]==thre && !used[tx][ty]){
      used[tx][ty]=true;
      dfs(tx, ty, thre);
    }
  }
  return;
}

int eval(int sx, int sy, int thre){
  REP(i, n){
    REP(j, n){
      used[i][j]=false;
    }
  }
  used[sx][sy]=true;
  dfs(sx, sy, thre);
  int cnt=0;
  REP(i, n){
    REP(j, n){
      if(used[i][j]){
        ++cnt;
      }
    }
  }
  return (cnt>=thre ? thre*cnt : 0);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  REP(i, n){
    REP(j, n){
      cin>>a[i][j];
    }
  }

  // ull time_limit=2965;
  // ull st=current_time_mills();
  // ull et=st+time_limit;
  // ull current_time=st;
  // while(current_time<et){
  //
  // }
  score=0;
  FOR(sx, 0, 50){
    FOR(sy, 0, 50){
      FOR(thre, 1, 20){
        if(a[sx][sy]>thre){
          continue;
        }
        int cnt=bfs(sx, sy, thre);
        if(cnt>=thre){
          int tmp=cnt*thre;
          // DEBUG(tmp);
          if(tmp>score){
            score=tmp;
            REP(i, m){
              ans[i][0]=ans_sub[i][0];
              ans[i][1]=ans_sub[i][1];
              ans[i][2]=ans_sub[i][2];
            }
          }
        }
      }
    }
  }

  // 出力
  REP(i, m){
    cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<'\n';
  }
  return 0;
}
