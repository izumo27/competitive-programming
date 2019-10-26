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

int b[2][3], c[3][2];
int dp[1333][1333];

int score(int x, int y){
  if(dp[x][y]){
    return dp[x][y];
  }
  int board[3][3], bit=0;
  REP(i, 3){
    REP(j, 3){
      board[i][j]=((x>>bit)&1)-((y>>bit)&1);
      // DEBUG(board[i][j]);
      if(!board[i][j]){
        return -1;
      }
      ++bit;
    }
  }
  int res=0;
  REP(i, 2){
    REP(j, 3){
      if(board[i][j]==board[i+1][j]){
        res+=b[i][j];
      }
    }
  }
  REP(i, 3){
    REP(j, 2){
      if(board[i][j]==board[i][j+1]){
        res+=c[i][j];
      }
    }
  }
  return res;
}

int dfs(int x, int y, int t){
  int s=score(x, y);
  if(s!=-1){
    return dp[x][y]=s;
  }
  if(t&1){
    dp[x][y]=1e9;
    int board[3][3], bit=0;
    REP(i, 3){
      REP(j, 3){
        if(((x>>bit)&1)-((y>>bit)&1)==0){
          dp[x][y]=min(dp[x][y], dfs(x, y+(1<<bit), t+1));
        }
        ++bit;
      }
    }
  }
  else{
    dp[x][y]=-1;
    int board[3][3], bit=0;
    REP(i, 3){
      REP(j, 3){
        if(((x>>bit)&1)-((y>>bit)&1)==0){
          dp[x][y]=max(dp[x][y], dfs(x+(1<<bit), y, t+1));
        }
        ++bit;
      }
    }
  }
  return dp[x][y];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int sum=0;
  REP(i, 2){
    REP(j, 3){
      cin>>b[i][j];
      sum+=b[i][j];
    }
  }
  REP(i, 3){
    REP(j, 2){
      cin>>c[i][j];
      sum+=c[i][j];
    }
  }
  cout<<dfs(0, 0, 0)<<'\n';
  cout<<sum-dp[0][0]<<'\n';
  return 0;
}
