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

pair<double, double> dis[625];
double d[625][625];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(10)<<fixed;
  int n, m;
  cin>>n>>m;
  vi g[625], h[625];
  REP(i, m){
    int s, t;
    cin>>s>>t;
    --s;--t;
    g[s].push_back(t);
    h[t].push_back(s);
  }
  dis[n-1]=make_pair(1, 0);
  FORR(i, 0, n){
    if(!h[i].size()) continue;
    auto a=dis[i];
    for(auto& x : h[i]){
      double p=1.0/(int)g[x].size();
      auto b=make_pair(a.first*p, p*(a.second+a.first));
      auto c=dis[x];
      dis[x]=make_pair(b.first+c.first, b.second+c.second);
      d[x][i]+=b.second;
    }
  }
  // REP(i, n){
  //   REP(j, n){
  //     cout<<d[i][j]<<" \n"[j==n-1];
  //   }
  // }
  // REP(i, n){
  //   cout<<dis[i].first<<' '<<dis[i].second<<'\n';
  // }
  REP(i, n){
    dis[i]=make_pair(0, 0);
  }
  dis[0]=make_pair(1, 0);
  REP(i, n){
    if(!g[i].size()) continue;
    double p=1.0/(int)g[i].size();
    auto a=dis[i];
    auto b=make_pair(a.first*p, p*(a.second+a.first));
    for(auto& x : g[i]){
      auto c=dis[x];
      dis[x]=make_pair(b.first+c.first, b.second+c.second);
    }
  }
  double ans=dis[n-1].second;
  REP(i, n){
    double ma=-1;
    int idx=-1;
    if((int)g[i].size()==1) continue;
    for(auto& x : g[i]){
      if(ma<d[i][x]){
        ma=d[i][x];
        idx=x;
      }
    }
    vi f[625];
    REP(j, n){
      for(auto& x : g[j]){
        if(j==i && x==idx) continue;
        f[j].push_back(x);
      }
    }
    REP(j, n){
      dis[j]=make_pair(0, 0);
    }
    dis[0]=make_pair(1, 0);
    REP(j, n){
      if(!f[j].size()) continue;
      double p=1.0/(int)f[j].size();
      auto a=dis[j];
      auto b=make_pair(a.first*p, p*(a.second+a.first));
      for(auto& x : f[j]){
        auto c=dis[x];
        dis[x]=make_pair(b.first+c.first, b.second+c.second);
      }
    }
    CHMIN(ans, dis[n-1].second);
  }
  cout<<ans<<'\n';
  return 0;
}
