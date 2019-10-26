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

constexpr int INF=1e9;
vi g[252521];
int d[252521];

void dfs(int s){
  for(auto x : g[s]){
    if(d[x]!=INF){
      continue;
    }
    d[x]=d[s]+1;
    dfs(x);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a, b;
  cin>>n;
  REP(i, n-1){
    cin>>a>>b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  REP(i, n){
    d[i]=INF;
  }
  d[0]=0;
  dfs(0);
  int ma=0, cand=0;
  REP(i, n){
    if(ma<d[i]){
      cand=i;
      ma=d[i];
    }
  }
  REP(i, n){
    d[i]=INF;
  }
  d[cand]=0;
  dfs(cand);
  int ans=0;
  REP(i, n){
    CHMAX(ans, d[i]);
  }
  cout<<(ans%3==1 ? "Second" : "First")<<'\n';
  return 0;
}
