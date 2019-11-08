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

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

// 入力
int n=100, a[100][100], q=1000;

// 最高スコア
int mscore;
// 最高スコアの手順
int x[1000], y[1000], h[1000];
// 最高スコアの高さ
int b[100][100];

// 乱数
unsigned int xor32() {
  static unsigned int x = 2463534242;
  x = x ^ (x << 13); x = x ^ (x >> 17);
  return x = x ^ (x << 15);
}

int score(const int idx, const int xx, const int yy, const int hh){
  int res=mscore;
  FOR(i, max(0, y[idx]-h[idx]+1), min(n, y[idx]+h[idx])){
    FOR(j, max(0, x[idx]-h[idx]+1+abs(y[idx]-i)), min(n, x[idx]+h[idx]-abs(y[idx]-i))){
      res=res+abs(a[i][j]-b[i][j])-abs(a[i][j]-b[i][j]+(h[idx]-abs(x[idx]-j)-abs(y[idx]-i)));
      b[i][j]-=h[idx]-abs(x[idx]-j)-abs(y[idx]-i);
    }
  }
  FOR(i, max(0, yy-hh+1), min(n, yy+hh)){
    FOR(j, max(0, xx-hh+1+abs(yy-i)), min(n, xx+hh-abs(yy-i))){
      res=res+abs(a[i][j]-b[i][j])-abs(a[i][j]-b[i][j]-(hh-abs(xx-j)-abs(yy-i)));
      b[i][j]+=hh-abs(xx-j)-abs(yy-i);
    }
  }
  return res;
}

// x, y, hの更新
void update(const int idx, const int xx, const int yy, const int hh){
  x[idx]=xx;
  y[idx]=yy;
  h[idx]=hh;
}

// bのrollback
void rollback(const int idx, const int xx, const int yy, const int hh){
  FOR(i, max(0, y[idx]-h[idx]+1), min(n, y[idx]+h[idx])){
    FOR(j, max(0, x[idx]-h[idx]+1+abs(y[idx]-i)), min(n, x[idx]+h[idx]-abs(y[idx]-i))){
      b[i][j]+=h[idx]-abs(x[idx]-j)-abs(y[idx]-i);
    }
  }
  FOR(i, max(0, yy-hh+1), min(n, yy+hh)){
    FOR(j, max(0, xx-hh+1+abs(yy-i)), min(n, xx+hh-abs(yy-i))){
      b[i][j]-=hh-abs(xx-j)-abs(yy-i);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  time_t start=clock();
  REP(i, n)REP(j, n){
    cin>>a[i][j];
  }
  mscore=2e8;
  REP(k, q){
    x[k]=xor32()%n;
    y[k]=xor32()%n;
    h[k]=xor32()%n+1;
    FOR(i, max(0, y[k]-h[k]+1), min(n, y[k]+h[k])){
      FOR(j, max(0, x[k]-h[k]+1+abs(y[k]-i)), min(n, x[k]+h[k]-abs(y[k]-i))){
        b[i][j]+=h[k]-abs(x[k]-j)-abs(y[k]-i);
      }
    }
  }
  REP(i, n)REP(j, n){
    mscore-=abs(a[i][j]-b[i][j]);
  }
  while(1){
    time_t now=clock();
    if((double)(now-start)/CLOCKS_PER_SEC*1000>5950){
      break;
    }
    int idx=xor32()%q;
    int xx=xor32()%n;
    int yy=xor32()%n;
    int hh=xor32()%n+1;
    int tscore=score(idx, xx, yy, hh);
    if(tscore>mscore){
      mscore=tscore;
      update(idx, xx, yy, hh);
    }
    else{
      rollback(idx, xx, yy, hh);
    }
  }
  cout<<q<<'\n';
  REP(i, q){
    cout<<x[i]<<' '<<y[i]<<' '<<h[i]<<'\n';
  }
  return 0;
}
