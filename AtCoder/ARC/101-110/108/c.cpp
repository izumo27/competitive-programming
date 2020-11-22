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

// constexpr ll MOD=1000000007ll;
constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

vector<pii> g[125252];
bool used[125252];
int ans[125252];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m;
  cin>>n>>m;
  REP(i, m){
    int u, v, c;
    cin>>u>>v>>c;
    --u;--v;
    g[u].push_back(pii(v, c));
    g[v].push_back(pii(u, c));
  }
  REP(i, n){
    ans[i]=-1;
  }
  queue<pii> que;
  que.push(pii(-1, 0));
  used[0]=true;
  ans[0]=1;
  while(!que.empty()){
    auto [s, t]=que.front();que.pop();
    for(auto& gg : g[t]){
      auto [x, c]=gg;
      if(!used[x]){
        used[x]=true;
        que.push(pii(t, x));
        if(c==ans[t]){
          ans[x]=(ans[t]==1 ? 2 : 1);
        }
        else{
          ans[x]=c;
        }
      }
    }
  }
  REP(i, n){
    cout<<ans[i]<<'\n';
  }
  return 0;
}
