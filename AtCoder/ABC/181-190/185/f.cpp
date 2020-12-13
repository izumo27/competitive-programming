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

template<typename T> struct SegmentTree_sum{
  int n;
  vector<T> node;
  T ZERO;

  SegmentTree_sum(const vector<T> &v, const T &ZERO_=0){
    init(v, ZERO_);
  }

  // n要素で初期化
  void init(const vector<T> &v, const T &ZERO_=0){
    int n_=v.size();
    n=1;
    while(n<n_){
      n<<=1;
    }
    node.resize(n*2-1);
    ZERO=ZERO_;
    REP(i, n_){
      node[i+n-1]=v[i];
    }
    FORR(i, 0, n-1){
      node[i]=(node[i*2+1]^node[i*2+2]);
    }
  }

  // k番目(0-indexed)をaに変更
  void update(int k, const T &a){
    k+=n-1;
    node[k]=(node[k]^a);
    while(k>0){
      k=(k-1)/2;
      node[k]=(node[k*2+1]^node[k*2+2]);
    }
  }

  // [a, b)の和を求める
  // k: 節点の番号、その節点は[l, r)に対応づく
  T query(int a, int b, int k, int l, int r){
    // [a, b)と[l, r)が交差しなければZERO
    if(r<=a || b<=l){
      return ZERO;
    }
    // [a, b)と[l, r)が完全に含んでいればこの節点の値
    if(a<=l && r<=b){
      return node[k];
    }
    // そうでなければ2つの子の和
    else{
      T v1=query(a, b, k*2+1, l, (l+r)/2), v2=query(a, b, k*2+2, (l+r)/2, r);
      return v1^v2;
    }
  }

  T query(int a, int b){
    return query(a, b, 0, 0, n);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, Q;
  vi a;
  cin>>n>>Q;
  REP(i, n){
    int aa;
    cin>>aa;
    a.push_back(aa);
  }
  SegmentTree_sum st(a);
  while(Q--){
    int t, x, y;
    cin>>t>>x>>y;
    --x;
    if(t==1){
      st.update(x, y);
    }
    else{
      --y;
      int res=st.query(x, y+1);
      cout<<res<<'\n';
    }
  }
  return 0;
}
