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

struct UnionFind{
  vi par;
  vi rank;

  UnionFind(int n=1){
    init(n);
  }

  // n要素で初期化
  void init(int n=1){
    par.resize(n);
    rank.resize(n);
    REP(i, n){
      par[i]=i;
      rank[i]=0;
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
    if(rank[x]<rank[y]){
      par[x]=y;
    }
    else{
      par[y]=x;
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[125252], b[125252];
  pii c[125252], d[125252];
  cin>>n;
  REP(i, n){
    cin>>a[i];
    c[i]=pii(a[i], i);
  }
  REP(i, n){
    cin>>b[i];
    d[i]=pii(b[i], i);
  }
  sort(c, c+n);
  sort(d, d+n);
  REP(i, n){
    if(c[i].first>d[i].first){
      cout<<"No"<<'\n';
      return 0;
    }
  }
  FOR(i, 1, n){
    if(c[i].first<=d[i-1].first){
      cout<<"Yes"<<'\n';
      return 0;
    }
  }
  UnionFind uf(n);
  REP(i, n){
    uf.unite(c[i].second, d[i].second);
  }
  bool ok=false;
  int root=uf.find(0);
  REP(i, n){
    // DEBUG(uf.find(i));
    if(root!=uf.find(i)){
      ok=true;
      break;
    }
  }
  cout<<(ok ? "Yes" : "No")<<'\n';
  return 0;
}
