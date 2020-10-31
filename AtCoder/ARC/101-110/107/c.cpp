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

template<typename T> struct Modint{
  using Type = typename decay<decltype(T::value)>::type;

  Type val;

  constexpr Modint() noexcept : val(){}
  template<typename U> constexpr Modint(const U& x) noexcept {val=normalize(x);}
  template<typename U> static Type normalize(const U& x) noexcept {
    Type v;
    if (-mod()<=x && x<mod()) v=static_cast<Type>(x);
    else v=static_cast<Type>(x%mod());
    if (v<0) v+=mod();
    return v;
  }

  constexpr Type& value() noexcept {return val;}
  constexpr const Type& value() const noexcept {return val;}
  template <typename U> constexpr explicit operator U() const noexcept {return static_cast<U>(val);}
  constexpr static Type mod() noexcept {return T::value;}

  constexpr Modint& operator+=(const Modint& rhs) noexcept {if((val+=rhs.val)>=mod()) val-=mod(); return *this;}
  template <typename U> constexpr Modint& operator+=(const U& rhs) noexcept {return *this+=Modint(rhs);}
  constexpr Modint& operator-=(const Modint& rhs) noexcept {if((val-=rhs.val)<0) val+=mod(); return *this;}
  template <typename U> constexpr Modint& operator-=(const U& rhs) noexcept {return *this-=Modint(rhs);}
  constexpr Modint& operator++() noexcept {return *this+=1;}
  constexpr Modint& operator--() noexcept {return *this-=1;}
  constexpr Modint operator++(int) noexcept {Modint result(*this); *this+=1; return result;}
  constexpr Modint operator--(int) noexcept {Modint result(*this); *this-=1; return result;}
  constexpr Modint operator-() const noexcept {return Modint(-val);}

  constexpr Modint& operator*=(const Modint rhs) noexcept {val=val*rhs.val%mod(); return *this;}
  constexpr Modint& operator/=(const Modint& rhs) noexcept {
    Type x=rhs.val, m=mod(), u=0, v=1;
    while(x!=0){
      Type t=m/x;
      m-=t*x; swap(x, m);
      u-=t*v; swap(u, v);
    }
    assert(m==1);
    return *this*=Modint(u);
  }
};

template<typename T> constexpr bool operator==(const Modint<T>& lhs, const Modint<T>& rhs) noexcept {return lhs.val==rhs.val;}
template<typename T, typename U> constexpr bool operator==(const Modint<T>& lhs, U rhs) noexcept {return lhs==Modint<T>(rhs);}
template<typename T, typename U> constexpr bool operator==(U lhs, const Modint<T>& rhs) noexcept { return Modint<T>(lhs)==rhs;}

template<typename T> constexpr bool operator!=(const Modint<T>& lhs, const Modint<T>& rhs) noexcept {return !(lhs==rhs);}
template<typename T, typename U> constexpr bool operator!=(const Modint<T>& lhs, U rhs) noexcept {return !(lhs==rhs);}
template<typename T, typename U> constexpr bool operator!=(U lhs, const Modint<T>& rhs) noexcept {return !(lhs==rhs);}

template<typename T> constexpr bool operator<(const Modint<T>& lhs, const Modint<T>& rhs) noexcept {return lhs.val<rhs.val;}
template<typename T, typename U> constexpr bool operator<(const Modint<T>& lhs, U rhs) noexcept {return lhs<Modint<T>(rhs);}
template<typename T, typename U> constexpr bool operator<(U lhs, const Modint<T>& rhs) noexcept {return Modint<T>(lhs)<rhs;}

template<typename T> constexpr bool operator>(const Modint<T>& lhs, const Modint<T>& rhs) noexcept {return lhs.val>rhs.val;}
template<typename T, typename U> constexpr bool operator>(const Modint<T>& lhs, U rhs) noexcept {return lhs>Modint<T>(rhs);}
template<typename T, typename U> constexpr bool operator>(U lhs, const Modint<T>& rhs) noexcept {return Modint<T>(lhs)>rhs;}

template<typename T> constexpr Modint<T> operator+(const Modint<T>& lhs, const Modint<T>& rhs) noexcept {return Modint<T>(lhs)+=rhs;}
template<typename T, typename U> constexpr Modint<T> operator+(const Modint<T>& lhs, U rhs) noexcept {return Modint<T>(lhs)+=rhs;}
template<typename T, typename U> constexpr Modint<T> operator+(U lhs, const Modint<T>& rhs) noexcept {return Modint<T>(lhs)+=rhs;}

template<typename T> constexpr Modint<T> operator-(const Modint<T>& lhs, const Modint<T>& rhs) noexcept {return Modint<T>(lhs)-=rhs;}
template<typename T, typename U> constexpr Modint<T> operator-(const Modint<T>& lhs, U rhs) noexcept {return Modint<T>(lhs)-=rhs;}
template<typename T, typename U> constexpr Modint<T> operator-(U lhs, const Modint<T>& rhs) noexcept {return Modint<T>(lhs)-=rhs;}

template<typename T> constexpr Modint<T> operator*(const Modint<T>& lhs, const Modint<T>& rhs) noexcept {return Modint<T>(lhs)*=rhs;}
template<typename T, typename U> constexpr Modint<T> operator*(const Modint<T>& lhs, U rhs) noexcept {return Modint<T>(lhs)*=rhs;}
template<typename T, typename U> constexpr Modint<T> operator*(U lhs, const Modint<T>& rhs) noexcept {return Modint<T>(lhs)*=rhs;}

template<typename T> constexpr Modint<T> operator/(const Modint<T>& lhs, const Modint<T>& rhs) noexcept {return Modint<T>(lhs)/=rhs;}
template<typename T, typename U> constexpr Modint<T> operator/(const Modint<T>& lhs, U rhs) noexcept {return Modint<T>(lhs)/=rhs;}
template<typename T, typename U> constexpr Modint<T> operator/(U lhs, const Modint<T>& rhs) noexcept {return Modint<T>(lhs)/=rhs;}

template<typename T, typename U> Modint<T> constexpr power(const Modint<T>& a, const U& b) noexcept {
  Modint<T> x=a, res=1;
  U p=b;
  while(p>0){
    if(p&1) res*=x;
    x*=x;
    p>>=1;
  }
  return res;
}

template<class T> struct Combination{
  using Type = typename decay<decltype(T::value)>::type;

  vector<Modint<T>> fact_, finv_;
  constexpr Combination(int n) noexcept : fact_(n+1, 1), finv_(n+1, 1) {
    Type MOD=fact_[0].mod();
    FOR(i, 2, n+1){
      fact_[i]=fact_[i-1]*i;
    }
    finv_[n]=power(fact_[n], MOD-2);
    FORR(i, 3, n+1){
      finv_[i-1]=finv_[i]*i;
    }
  }
  // iの逆元も求める場合
  /*
  vector<Modint<T>> fact_, inv_, finv_;
  constexpr Combination(int n) noexcept : fact_(n+1, 1), inv_(n+1, 1), finv_(n+1, 1) {
    Type MOD=fact_[0].mod();
    FOR(i, 2, n+1){
      fact_[i]=fact_[i-1]*i;
      inv_[i]=-inv_[MOD%i]*(MOD/i);
      finv_[i]=finv_[i-1]*inv_[i];
    }
  }
  constexpr Modint<T> inv(int n) const noexcept {
    if(n<0) return 0;
    return inv_[n];
  }
  */
  constexpr Modint<T> com(int n, int k) const noexcept {
    if(n<k || n<0 || k<0) return Modint<T>(0);
    return fact_[n]*finv_[k]*finv_[n-k];
  }
  constexpr Modint<T> fact(int n) const noexcept {
    if(n<0) return  Modint<T>(0);
    return fact_[n];
  }
  constexpr Modint<T> finv(int n) const noexcept {
    if(n<0) return  Modint<T>(0);
    return finv_[n];
  }
};

template<typename T> constexpr ostream& operator<<(ostream& stream, const Modint<T>& number) noexcept {
  return stream<<number.val;
}

template<typename T> constexpr istream& operator>>(istream& stream, Modint<T>& number) noexcept {
  return stream>>number.val;
}

using Mint = Modint<integral_constant<decay<decltype(MOD)>::type, MOD>>;
using Comb = Combination<integral_constant<decay<decltype(MOD)>::type, MOD>>;

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

int sz1[52], sz2[52];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, k, a[52][52];
  cin>>n>>k;
  REP(i, n){
    REP(j, n){
      cin>>a[i][j];
    }
  }
  UnionFind uf1(n);
  REP(i, n){
    FOR(j, i+1, n){
      bool ok=true;
      REP(l, n){
        if(a[i][l]+a[j][l]>k){
          ok=false;
          break;
        }
      }
      if(ok){
        uf1.unite(i, j);
      }
    }
  }
  UnionFind uf2(n);
  REP(i, n){
    FOR(j, i+1, n){
      bool ok=true;
      REP(l, n){
        if(a[l][i]+a[l][j]>k){
          ok=false;
          break;
        }
      }
      if(ok){
        uf2.unite(i, j);
      }
    }
  }
  REP(i, n){
    ++sz1[uf1.find(i)];
    ++sz2[uf2.find(i)];
  }
  Mint ans=1;
  REP(i, n){
    FOR(j, 1, sz1[i]+1){
      ans*=j;
    }
    FOR(j, 1, sz2[i]+1){
      ans*=j;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
