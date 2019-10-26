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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
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

ll INF=1e18;
bool used[114514];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m, x, y;
  ll a[114514];
  cin>>n>>m;
  REP(i, n){
    cin>>a[i];
  }
  UnionFind uf(n);
  REP(i, m){
    cin>>x>>y;
    uf.unite(x, y);
  }
  pair<ll, int> mi[114514];
  REP(i, n){
    mi[i]=make_pair(INF, i);
  }
  int cnt=0;
  REP(i, n){
    int par=uf.find(i);
    if(i==par){
      ++cnt;
    }
    if(mi[par].first>a[i]){
      mi[par]=make_pair(a[i], i);
    }
  }
  if(cnt==1){
    cout<<0<<'\n';
    return 0;
  }
  ll ans=0;
  REP(i, n){
    int par=uf.find(i);
    if(i!=par){
      continue;
    }
    ans+=mi[par].first;
    a[mi[par].second]=INF;
  }
  sort(a, a+n);
  REP(i, cnt-2){
    if(a[i]==INF){
      cout<<"Impossible"<<'\n';
      return 0;
    }
    ans+=a[i];
  }
  cout<<ans<<'\n';
  return 0;
}
