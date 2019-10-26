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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const int INF=1e9;
const int MAX_V=114514;

// cost[i][j]: 辺e=(i, j)のコスト(存在しない場合はINF)
int cost[MAX_V][MAX_V];
// 頂点sからの最短距離
int d[MAX_V];
bool used[MAX_V];
// 最短路の直前の頂点
int prev[MAX_V];
int V;

// 最短路も求める場合
void dijkstra(int s){
  fill(d, d+V, INF);
  fill(used, used+V, false);
  fill(prev, prev+V, -1);
  d[s]=0;
  while(true){
    int v=-1;
    REP(i, V){
      if(!used[i] && (v==-1 || d[i]<d[v])){
        v=u;
      }
    }
    if(v==-1){
      break;
    }
    used[v]=true;
    REP(i, V){
      if(d[i]>d[v]+cost[v][i]){
        d[i]=d[u]+cost[v][i];
        prev[i]=v;
      }
    }
  }
}

// 頂点tへの最短路
vi get_path(int t){
  vi path;
  for(; t!=-1; t=prev[t]){
    path.push_back(t);
  }
  reverse(ALL(path));
  return path;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}
