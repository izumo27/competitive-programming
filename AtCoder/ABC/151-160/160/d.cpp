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

const double EPS=1e-9;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int ans[2525];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, x, y;
  cin>>n>>x>>y;
  --x;--y;
  vi g[2525];
  REP(i, n-1){
    g[i].push_back(i+1);
    g[i+1].push_back(i);
  }
  g[x].push_back(y);
  g[y].push_back(x);
  REP(i, n){
    int d[2525];
    bool used[2525];
    REP(j, n){
      d[j]=0;
      used[j]=false;
    }
    queue<int> que;
    que.push(i);
    used[i]=true;
    while(que.size()){
      int s=que.front();que.pop();
      for(auto t : g[s]){
        if(used[t]){
          continue;
        }
        used[t]=true;
        d[t]=d[s]+1;
        que.push(t);
      }
    }
    REP(j, n){
      ++ans[d[j]];
    }
  }
  FOR(i, 1, n){
    cout<<ans[i]/2<<'\n';
  }
  return 0;
}
