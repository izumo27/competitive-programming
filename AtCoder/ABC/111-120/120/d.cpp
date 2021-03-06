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

const int MOD=1000000007;
// const ll MOD=998244353ll;
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

int sz[114514];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  int m, a[114514], b[114514];
  cin>>n>>m;
  REP(i, m){
    cin>>a[i]>>b[i];
    --a[i];
    --b[i];
  }
  REP(i, n){
    sz[i]=1;
  }
  UnionFind uf(n);
  ll ans[114514];
  ans[m-1]=n*(n-1)/2;
  FORR(i, 1, m){
    if(uf.issame(a[i], b[i])){
      ans[i-1]=ans[i];
    }
    else{
      ll asz=sz[uf.find(a[i])], bsz=sz[uf.find(b[i])];
      ans[i-1]=ans[i]-asz*bsz;
      uf.unite(a[i], b[i]);
      sz[uf.find(a[i])]=asz+bsz;
    }
  }
  REP(i, m){
    cout<<ans[i]<<'\n';
  }
  return 0;
}
