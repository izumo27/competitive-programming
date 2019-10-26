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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

template<class Abel> struct UnionFind{
  vi par;
  vi rank;
  vector<Abel> diff_weight;

  UnionFind(int n=1, Abel SUM_UNITY=0){
    init(n, SUM_UNITY);
  }

  // n要素で初期化
  void init(int n=1, Abel SUM_UNITY=0){
    par.resize(n);
    rank.resize(n);
    diff_weight.resize(n);
    REP(i, n){
      par[i]=i;
      rank[i]=0;
      diff_weight[i]=SUM_UNITY;
    }
  }

  // 重みを更新しながらxの根を求める
  int find(int x){
    if(par[x]==x){
      return x;
    }
    else{
      int r=find(par[x]);
      diff_weight[x]+=diff_weight[par[x]];
      return par[x]=r;
    }
  }

  Abel weight(int x){
    find(x);
    return diff_weight[x];
  }

  // weight(y)-weight(x)=wとなるようにxとyが属する集合を併合
  bool unite(int x, int y, Abel w){
    w+=weight(x);
    w-=weight(y);
    x=find(x);
    y=find(y);
    if(x==y){
      return false;
    }
    if(rank[x]<rank[y]){
      par[x]=y;
      diff_weight[x]=-w;
    }
    else{
      par[y]=x;
      diff_weight[y]=w;
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

  Abel diff(int x, int y){
    return weight(y)-weight(x);
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}
