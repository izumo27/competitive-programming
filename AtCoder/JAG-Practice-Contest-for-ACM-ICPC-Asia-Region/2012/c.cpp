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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const int INF=1e9;
const int MAX_N=1252;
const int MAX_E=12525;

struct edge{
  int u;
  int v;
  int cost;
};

int root[MAX_N], depth[MAX_N];

edge es[MAX_E];
int V, E;

bool comp(const edge& e1, const edge& e2){
  return e1.cost<e2.cost;
}

// n要素で初期化
void init_union_find(int n){
  REP(i, n){
    root[i]=i;
    depth[i]=0;
  }
}

// xの根を求める
int find(int x){
  if(root[x]==x){
    return x;
  }
  else{
    return root[x]=find(root[x]);
  }
}

// xとyが属する集合を併合
void unite(int x, int y){
  x=find(x);
  y=find(y);
  if(x==y){
    return;
  }
  if(depth[x]<depth[y]){
    root[x]=y;
  }
  else{
    root[y]=x;
    if(depth[x]==depth[y]){
      ++depth[x];
    }
  }
  return;
}

// xとyが同じ集合に属するか判定
bool same(int x, int y){
  return find(x)==find(y);
}

int kruskal(){
  sort(es, es+E, comp);
  init_union_find(V);
  int res=0;
  int cnt=0;
  REP(i, E){
    edge e=es[i];
    if(!same(e.u, e.v)){
      unite(e.u, e.v);
      ++cnt;
      if(cnt==(V>>1)){
        res=e.cost;
        break;
      }
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  while(true){
    int n, m, s, t;
    cin>>n>>m;
    if(n==0 && m==0){
      break;
    }
    V=n;
    E=m;
    REP(i, m){
      edge e;
      cin>>s>>t>>e.cost;
      e.u=s-1;
      e.v=t-1;
      es[i]=e;
    }
    cout<<kruskal()<<'\n';
  }
  return 0;
}
