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

struct UnionFind{
  vi par;
  vi rank;
  vi sz;

  UnionFind(int n=1){
    init(n);
  }

  // n要素で初期化
  void init(int n=1){
    par.resize(n);
    rank.resize(n);
    sz.resize(n);
    REP(i, n){
      par[i]=i;
      rank[i]=0;
      sz[i]=1;
    }
  }

  // xの根を求める
  int find(int x){
    if(par[x]==x){
      return x;
    }
    else{
      return par[x]=find(par[x]);
    }
  }

  // xとyが属する集合を併合
  bool unite(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y){
      return false;
    }
    int szx=sz[x], szy=sz[y];
    if(rank[x]<rank[y]){
      par[x]=y;
      sz[y]=szx+szy;
    }
    else{
      par[y]=x;
      sz[x]=szx+szy;
      if(rank[x]==rank[y]){
        ++rank[x];
      }
    }
    return true;
  }

  // xとyが同じ集合に属するか判定
  bool issame(int x, int y){
    return find(x)==find(y);
  }
};

struct edge{
  double d;
  int from;
  int to;
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(10)<<fixed;
  int n;
  double x[125], y[125];
  cin>>n;
  vector<edge> es;
  REP(i, n){
    cin>>x[i]>>y[i];
    es.push_back({(100-y[i])/2, 0, i+1});
    es.push_back({(y[i]-(-100))/2, i+1, n+1});
  }
  REP(i, n){
    FOR(j, i+1, n){
      es.push_back({hypot(x[i]-x[j], y[i]-y[j])/2, i+1, j+1});
    }
  }
  sort(ALL(es), [](edge a, edge b){
    return a.d<b.d;
  });
  UnionFind uf(n+2);
  for(auto& e : es){
    uf.unite(e.from, e.to);
    // DEBUG(e.from);
    // DEBUG(e.to);
    // DEBUG(e.d);
    // DEBUG(uf.sz[uf.find(e.from)]);
    if(uf.issame(0, n+1)){
      cout<<e.d<<'\n';
      return 0;
    }
  }
  return 0;
}
