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

template<typename T> struct LazySegmentTree_sum{
  int n;
  vector<T> node, lazy;
  T ZERO;

  LazySegmentTree_sum(const int &n_=1, const T &ZERO_=0){
    init(n_, ZERO_);
  }

  // nodeの初期化
  void init(const int &n_=1, const T &ZERO_=0){
    n=1;
    while(n<n_){
      n<<=1;
    }
    node.resize(n*2-1);
    lazy.resize(n*2-1, 0);
    ZERO=ZERO_;
    // REP(i, n_){
    //   node[i+n-1]=v[i];
    // }
    // FORR(i, 0, n-1){
    //   node[i]=node[i*2+1]+node[i*2+2];
    // }
  }

  // k番目(0-indexed)を遅延評価
  void eval(int k, int l, int r){
    // 遅延配列が空なら子へ伝搬しない
    if(lazy[k]==0){
      return;
    }
    node[k]=lazy[k];
    // 最下段でなければ伝搬
    if(r-l>1){
      lazy[k*2+1]=lazy[k]/2;
      lazy[k*2+2]=lazy[k]/2;
    }
    lazy[k]=0;
  }

  // k番目(0-indexed)をaに変更
  void update(int k, const T &a){
    k+=n-1;
    node[k]=a;
    while(k>0){
      k=(k-1)/2;
      node[k]=node[k*2+1]+node[k*2+2];
    }
  }

  // [a, b)にxを加える
  // k: 節点の番号、その節点は[l, r)に対応づく
  // 外から呼び出すときはadd(a, b, x, 0, 0, n)
  void add(int a, int b, const T &x, int k, int l, int r){
    eval(k, l, r);
    // [a, b)と[l, r)が交差しなければ何もしない
    if(r<=a || b<=l){
      return;
    }
    // [a, b)と[l, r)が完全に含んでいれば遅延配列に値を入れて評価
    if(a<=l && r<=b){
      lazy[k]+=(r-l)*x;
      eval(k, l, r);
    }
    // そうでなければ子を再帰的に計算し更新
    else{
      add(a, b, x, k*2+1, l, (l+r)/2);
      add(a, b, x, k*2+2, (l+r)/2, r);
      node[k]=node[k*2+1]+node[k*2+2];
    }
  }

  // [a, b)の和を求める
  // k: 節点の番号、その節点は[l, r)に対応づく
  // 外から呼び出すときはquery(a, b, 0, 0, n)
  T query(int a, int b, int k, int l, int r){
    // [a, b)と[l, r)が交差しなければZERO
    if(r<=a || b<=l){
      return ZERO;
    }
    eval(k, l, r);
    // [a, b)と[l, r)が完全に含んでいればこの節点の値
    if(a<=l && r<=b){
      return node[k];
    }
    // そうでなければ2つの子の和
    else{
      T v1=query(a, b, k*2+1, l, (l+r)/2), v2=query(a, b, k*2+2, (l+r)/2, r);
      return v1+v2;
    }
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, l, r;
  ll t;
  cin>>n>>m;
  LazySegmentTree_sum<ll> lst(n);
  REP(i, m){
    cin>>t>>l>>r;
    lst.add(l-1, r, t, 0, 0, lst.n);
  }
  cout<<lst.query(0, n, 0, 0, lst.n)<<'\n';
  return 0;
}
