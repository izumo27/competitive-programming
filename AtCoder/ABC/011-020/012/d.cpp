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
const int MAX_V=364;

// d[i][j]: 辺e=(i, j)のコスト(存在しない場合はINF, d[i][i]=0)
// d[i][i]が負になる場合は負の閉路が存在
int d[MAX_V][MAX_V];
int V;

void warshall_floyd(){
  REP(k, V){
    REP(i, V){
      REP(j, V){
        d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, a, b, t;
  cin>>n>>m;
  V=n;
  fill(d[0], d[n], INF);
  REP(i, n){
    d[i][i]=0;
  }
  REP(i, m){
    cin>>a>>b>>t;
    d[a-1][b-1]=d[b-1][a-1]=t;
  }
  warshall_floyd();
  int ans=1e9;
  REP(i, n){
    int tmp=0;
    REP(j, n){
      if(i!=j){
        tmp=max(tmp, d[i][j]);
      }
    }
    ans=min(tmp, ans);
  }
  cout<<ans<<'\n';
  return 0;
}
