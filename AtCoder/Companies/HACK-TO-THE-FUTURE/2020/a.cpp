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

constexpr int MOD=40;
// constexpr ll MOD=998244353ll;
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

constexpr int INF=1e9;

int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};

// 入力
int n=40, m=100, b=300, gx, gy, rx[100], ry[100];
int c[100];
bool block[40][40];

// 方向マスを置いたか
bool put[40][40];
// 方向マスの向き
int d[40][40];

// 最高スコア
int mscore;
// 方向マスを置いたか
bool mput[40][40];
// 方向マスの向き
int md[40][40];

// 乱数
unsigned int xor32() {
  static unsigned int x = 2463534242;
  x = x ^ (x << 13); x = x ^ (x >> 17);
  return x = x ^ (x << 15);
}

int eval(){
  int A=0, B=0, C=0;
  // i番目のロボットが(x, y)に向きjだったときがあるか
  bool used[100][40][40][4];
  REP(i, m)REP(x, n)REP(y, n)REP(j, 4){
    used[i][x][y][j]=false;
  }
  REP(i, m){
    int rd=c[i];
    Mint x=rx[i], y=ry[i];
    while(true){
      if(x==gx && y==gy){
        ++A;
        used[i][(int)x][(int)y][rd]=true;
        break;
      }
      if(put[(int)x][(int)y]){
        rd=d[(int)x][(int)y];
      }
      if(block[(int)x][(int)y] || used[i][(int)x][(int)y][rd]) break;
      used[i][(int)x][(int)y][rd]=true;
      x+=dx[rd];
      y+=dy[rd];
    }
  }
  REP(x, n)REP(y, n){
    if(put[x][y]) ++B;
  }
  REP(x, n)REP(y, n)REP(i, m)REP(j, 4){
    if(used[i][x][y][j]){
      ++C;
      i=m;
      j=4;
    }
  }
  return 1000*A-10*B+C;
}

void update(){
  REP(x, n)REP(y, n){
    mput[x][y]=put[x][y];
    md[x][y]=d[x][y];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  time_t start=clock();
  cin>>n>>m>>b;
  cin>>gx>>gy;
  REP(i, m){
    char tc;
    cin>>rx[i]>>ry[i]>>tc;
    if(tc=='U') c[i]=0;
    else if(tc=='D') c[i]=1;
    else if(tc=='L') c[i]=2;
    else c[i]=3;
  }
  REP(i, b){
    int bx, by;
    cin>>bx>>by;
    block[bx][by]=true;
  }
  int mscore=eval();
  update();

  REP(i, m){
    deque<pair<pii, int>> q;
    q.push_back(make_pair(make_pair(rx[i], ry[i]), c[i]));
    int num[40][40][4];
    REP(x, n)REP(y, n)REP(j, 4){
      num[x][y][j]=INF;
    }
    num[rx[i]][ry[i]][c[i]]=0;
    int bfr=INF;
    while(q.size()){
      auto s=q.front();
      q.pop_front();
      auto xy=s.first;
      int x=xy.first, y=xy.second;
      int rd=s.second;
      if(x==gx && y==gy){
        bfr=num[x][y][rd];
        break;
      }
      // 方向案内が置かれているときはそれに従う
      if(put[x][y]){
        int dir=d[x][y];
        int tx=(x+dx[dir]+n)%n, ty=(y+dy[dir]+n)%n;
        if(num[tx][ty][dir]!=INF){
          continue;
        }
        num[tx][ty][dir]=num[x][y][rd];
        q.push_front(make_pair(make_pair(tx, ty), dir));
      }
      else{
        REP(j, 4){
          int tx=(x+dx[j]+n)%n, ty=(y+dy[j]+n)%n;
          if(block[tx][ty] || num[tx][ty][j]!=INF){
            continue;
          }
          num[tx][ty][j]=num[x][y][rd];
          if(j==rd){
            q.push_front(make_pair(make_pair(tx, ty), j));
          }
          else{
            ++num[tx][ty][j];
            q.push_back(make_pair(make_pair(tx, ty), j));
          }
        }
      }
    }
    if(bfr==INF){
      continue;
    }
    // 経路復元
    bool used[40][40];
    REP(x, n)REP(y, n){
      used[x][y]=false;
    }
    int x=gx, y=gy;
    int mi=INF, rd=-1;
    used[x][y]=true;
    REP(j, 4){
      if(num[x][y][j]<mi){
        mi=num[x][y][j];
        rd=j;
      }
    }
    while(x!=rx[i] || y!=ry[i]){
      int tx=(x-dx[rd]+n)%n, ty=(y-dy[rd]+n)%n;
      used[tx][ty]=true;
      int mi=INF, idx=-1;
      REP(j, 4){
        int ttx=(tx-dx[j]+n)%n, tty=(ty-dy[j]+n)%n;
        if(used[ttx][tty]){
          continue;
        }
        if(num[tx][ty][j]<mi){
          mi=num[tx][ty][j];
          idx=j;
        }
      }
      // 方向案内を置く
      if(mi<bfr){
        put[tx][ty]=true;
        d[tx][ty]=rd;
      }
      bfr=mi;
      rd=idx;
      x=tx;
      y=ty;
    }
  }
  int tscore=eval();
  if(tscore>mscore){
    mscore=tscore;
    update();
  }

  // while(1){
  //   time_t now=clock();
  //   if((double)(now-start)/CLOCKS_PER_SEC*1000>2950){
  //     break;
  //   }
  //   int put_cnt=0;
  //   // int max_put=xor32()%100;
  //   int max_put=100;
  //   while(put_cnt<max_put){
  //     int x=xor32()%n;
  //     int y=xor32()%n;
  //     if(put[x][y]) continue;
  //     REP(x, n)REP(y, n){
  //       put[x][y]=false;
  //     }
  //     ++put_cnt;
  //     put[x][y]=true;
  //     d[x][y]=xor32()%4;
  //   }
  //   int tscore=eval();
  //   // DEBUG(tscore);
  //   if(tscore>mscore){
  //     mscore=tscore;
  //     update();
  //   }
  // }
  // cout<<mscore<<'\n';
  int k=0;
  REP(x, n)REP(y, n){
    if(mput[x][y]) ++k;
  }
  cout<<k<<'\n';
  REP(x, n)REP(y, n){
    if(mput[x][y]){
      cout<<x<<' '<<y<<' ';
      char r;
      if(md[x][y]==0) r='U';
      else if(md[x][y]==1) r='D';
      else if(md[x][y]==2) r='L';
      else r='R';
      cout<<r<<'\n';
    }
  }
  return 0;
}
