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

const int MAX_V=114514;

vi g[MAX_V];

ll dp[2][114514];

void dfs(int x, int p){
  ll s=1, t=1;
  for(int i : g[x]){
    if(i==p){
      continue;
    }
    dfs(i, x);
    s=(s*dp[1][i])%MOD;
    t=(t*dp[0][i])%MOD;
  }
  dp[1][x]=t;
  dp[0][x]=s+t;
  if(dp[0][x]>=MOD){
    dp[0][x]-=MOD;
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin>>n;
  REP(i, n-1){
    cin>>a>>b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, 0);
  cout<<dp[0][0]<<'\n';
  return 0;
}
