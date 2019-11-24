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

vector<pii> g[125252];
int ans[125252];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[125252], b[125252];
  cin>>n;
  REP(i, n-1){
    cin>>a[i]>>b[i];
    --a[i];--b[i];
    g[a[i]].emplace_back(b[i], i);
    g[b[i]].emplace_back(a[i], i);
  }
  int sz=1;
  queue<pii> q;
  q.emplace(0, 0);
  while(q.size()){
    auto ic=q.front();
    int i=ic.first, c=ic.second;
    q.pop();
    int col=1;
    for(auto& x : g[i]){
      int y=x.first, j=x.second;
      if(ans[j]){
        continue;
      }
      if(col==c){
        ++col;
      }
      ans[j]=col;
      q.emplace(y, col);
      CHMAX(sz, col);
      ++col;
      // DEBUG(y);
    }
  }
  cout<<sz<<'\n';
  REP(i, n-1){
    cout<<ans[i]<<'\n';
  }
  return 0;
}
