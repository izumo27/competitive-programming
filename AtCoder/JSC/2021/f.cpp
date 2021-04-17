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

// constexpr ll MOD=1000000007ll;
constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)


template<typename T> struct SegmentTree_sum{
  int n;
  vector<T> node;
  T ZERO;

  SegmentTree_sum(const int &n_=1, const T &ZERO_=0){
    init(n_, ZERO_);
  }

  // n要素で初期化
  void init(const int &n_=1, const T &ZERO_=0){
    n=1;
    while(n<n_){
      n<<=1;
    }
    node.resize(n*2-1);
    ZERO=ZERO_;
    REP(i, n*2-1){
      node[i]=ZERO;
    }
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
      return v1+v2;
    }
  }

  T query(int a, int b){
    return query(a, b, 0, 0, n);
  }
};

template <typename T>
vector<T> compress(vector<T> &X) {
    // ソートした結果を vals に
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    // 各要素ごとに二分探索で位置を求める
    for (int i = 0; i < (int)X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}

ll a[252521], b[252521], idxa[252521], idxb[252521];
constexpr int MAXY=252521;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m, q;
  cin>>n>>m>>q;
  SegmentTree_sum<ll> st1(MAXY+1), st2(MAXY+1);   // 和
  SegmentTree_sum<ll> st3(MAXY+1), st4(MAXY+1);  // 個数
  int T[252521];
  vl X(q), Y(q+1);
  REP(i, q){
    cin>>T[i]>>X[i]>>Y[i+1];
    --X[i];
  }
  vl YY=compress(Y);
  st3.update(0, n);
  st4.update(0, m);
  ll ans=0;
  REP(i, q){
    int t=T[i];
    ll x=X[i], y=Y[i+1], yy=YY[y];
    if(t==1){
      ans+=(yy*st4.query(0, y)+st2.query(y, MAXY))-(a[x]*st4.query(0ll, idxa[x])+st2.query(idxa[x], MAXY));
      cout<<ans<<'\n';
      // 値の更新
      {
        ll tmp=st1.query(y, y+1);
        st1.update(y, tmp+yy);
        tmp=st1.query(idxa[x], idxa[x]+1);
        st1.update(idxa[x], tmp-a[x]);
      }
      {
        ll tmp=st3.query(y, y+1);
        st3.update(y, tmp+1);
        tmp=st3.query(idxa[x], idxa[x]+1);
        st3.update(idxa[x], tmp-1);
      }
      a[x]=yy;
      idxa[x]=y;
    }
    else{
      ans+=(yy*st3.query(0, y)+st1.query(y, MAXY))-(b[x]*st3.query(0ll, idxb[x])+st1.query(idxb[x], MAXY));
      cout<<ans<<'\n';
      // 値の更新
      {
        ll tmp=st2.query(y, y+1);
        st2.update(y, tmp+yy);
        tmp=st2.query(idxb[x], idxb[x]+1);
        st2.update(idxb[x], tmp-b[x]);
      }
      {
        ll tmp=st4.query(y, y+1);
        st4.update(y, tmp+1);
        tmp=st4.query(idxb[x], idxb[x]+1);
        st4.update(idxb[x], tmp-1);
      }
      b[x]=yy;
      idxb[x]=y;
    }
  }
  return 0;
}
