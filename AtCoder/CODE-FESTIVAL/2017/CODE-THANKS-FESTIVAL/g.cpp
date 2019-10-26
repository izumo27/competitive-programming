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

bool g[50][50], ind1[1364364], ind2[1364364];
int dp1[1364364], dp2[1364364];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, a, b;
  cin>>n>>m;
  int n1=n>>1, n2=(n+1)>>1;
  REP(i, 1<<n1){
    ind1[i]=true;
  }
  REP(i, 1<<n2){
    ind2[i]=true;
  }
  REP(i, m){
    cin>>a>>b;
    --a;
    --b;
    g[a][b]=g[b][a]=true;
    if(a<n1 && b<n1){
      ind1[1<<a|1<<b]=false;
    }
    if(a>=n1 && b>=n1){
      a-=n1;
      b-=n1;
      ind2[1<<a|1<<b]=false;
    }
  }
  // 前半の独立集合を求める
  FOR(i, 2, n1){
    int sub=(1<<i)-1;
    while(sub<1<<n1){
      if(!ind1[sub]){
        REP(j, n1){
          ind1[sub|1<<j]=false;
        }
      }
      int x=sub&-sub, y=sub+x;
      sub=((sub&~y)/x>>1)|y;
    }
  }
  // 後半の独立集合を求める
  FOR(i, 2, n2){
    int sub=(1<<i)-1;
    while(sub<1<<n2){
      if(!ind2[sub]){
        REP(j, n2){
          ind2[sub|1<<j]=false;
        }
      }
      int x=sub&-sub, y=sub+x;
      sub=((sub&~y)/x>>1)|y;
    }
  }
  // 前半とつながっていない後半の集合を求める
  dp1[0]=1<<n2-1;
  REP(i, n1){
    REP(j, n2){
      if(!g[i][j+n1]){
        dp1[1<<i]|=1<<j;
      }
    }
  }
  FOR(i, 1, n1){
    int sub=(1<<i)-1;
    while(sub<1<<n1){
      REP(j, n1){
        dp1[sub|1<<j]=dp1[sub]&dp1[1<<j];
      }
      int x=sub&-sub, y=sub+x;
      sub=((sub&~y)/x>>1)|y;
    }
  }
  // 後半集合の最大独立サイズを求める
  REP(i, 1<<n2){
    if(ind2[i]){
      int cnt=0;
      REP(j, n2){
        if(i>>j&1){
          ++cnt;
        }
      }
      dp2[i]=cnt;
    }
  }
  FOR(i, 1, n2){
    int sub=(1<<i)-1;
    while(sub<1<<n2){
      REP(j, n2){
        dp2[sub|1<<j]=max(dp2[sub|1<<j], dp2[sub]);
      }
      int x=sub&-sub, y=sub+x;
      sub=((sub&~y)/x>>1)|y;
    }
  }

  int ans=0;
  REP(i, 1<<n1){
    if(ind1[i]){
      int tmp=dp2[dp1[i]];
      REP(j, n1){
        if(i>>j&1){
          ++tmp;
        }
      }
      ans=max(ans, tmp);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
