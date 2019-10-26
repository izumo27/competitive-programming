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
#define CHMAX(a, b) a=min((a), (b))

const int MOD=1000000007;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int n, m, a[60], b[60];
bool visited[60];
bool g[60][60];

void dfs(int i){
  visited[i]=true;
  REP(j, n){
    if(visited[j] || !g[i][j]) continue;
    dfs(j);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  REP(i, m){
    cin>>a[i]>>b[i];
    --a[i];
    --b[i];
    g[a[i]][b[i]]=g[b[i]][a[i]]=true;
  }
  int ans=0;
  REP(i, m){
    g[a[i]][b[i]]=g[b[i]][a[i]]=false;
    REP(j, n) visited[j]=false;
    dfs(0);
    bool ok=false;
    REP(j, n){
      if(!visited[j]) ok=true;
    }
    if(ok) ++ans;
    g[a[i]][b[i]]=g[b[i]][a[i]]=true;
  }
  cout<<ans<<'\n';
  return 0;
}
