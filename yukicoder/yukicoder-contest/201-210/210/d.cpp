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

const int INF=1<<30;

vi g[114514];
int sz[114514];
bool used[114514];
int n, m, p, q, Q, a;

int bfs(int s){
  int res=0;
  queue<pii> q;
  q.push(pii(s, 0));
  REP(i, n){
    used[i]=false;
  }
  used[s]=true;
  while(q.size()){
    pii p=q.front();
    q.pop();
    for(int x : g[p.first]){
      if(!used[x]){
        q.push(pii(x, p.second+1));
        res=p.second+1;
        used[x]=true;
      }
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n>>m;
  UnionFind uf(n);
  REP(i, m){
    cin>>p>>q;
    --p;
    --q;
    g[p].push_back(q);
    g[q].push_back(p);
    uf.unite(p, q);
  }
  REP(i, n){
    ++sz[uf.find(i)];
  }
  cin>>Q;
  REP(i, Q){
    cin>>a;
    --a;
    // DEBUG(a);
    int res=bfs(a);
    // DEBUG(res);
    int ans=0, tmp=1;
    while(tmp<res){
      ++ans;
      tmp*=2;
    }
    cout<<sz[uf.find(a)]-1<<' '<<ans<<'\n';
  }
  return 0;
}
