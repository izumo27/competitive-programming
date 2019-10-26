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

int root[114514], depth[114514];

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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin>>n>>q;
  // 初期化
  REP(i, n){
    root[i]=i;
    depth[i]=0;
  }
  int p, a, b;
  REP(i, q){
    cin>>p>>a>>b;
    if(p==0){
      unite(a, b);
    }
    else{
      cout<<(same(a, b) ? "Yes" : "No")<<'\n';
    }
  }
  return 0;
}
