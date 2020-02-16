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

// 乱数
unsigned int xor32() {
  static unsigned int x = 2463534242;
  x = x ^ (x << 13); x = x ^ (x >> 17);
  return x = x ^ (x << 15);
}

//入力
int N, W, K, V;
// ブロックの色、価値
int c[1252], v[1252];

// 出力
int ans[1252];
int tans[1252];

// フィールドにあるブロックが何番目か
vi num[8];
// スコア計算用
vi tnum[8];
// i番目のブロックの高さ
int h[1252];
int th[1252];

// 最高得点
int score;

int val(){
  int res=0;
  REP(i, N){
    int cnt=0;
    int tmp[K];
    REP(j, K){
      tmp[j]=0;
    }
    REP(j, W){
      if(tnum[j].size()<=i){
        continue;
      }
      ++cnt;
      auto x=tnum[j];
      tmp[c[x[i]]]+=v[x[i]];
    }
    if(!cnt){
      break;
    }
    int ma=0;
    REP(j, K){
      CHMAX(ma, tmp[j]);
    }
    res+=ma;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  time_t start=clock();
  cin>>N>>W>>K>>V;
  REP(i, N){
    cin>>c[i]>>v[i];
  }
  REP(i, N){
    ans[i]=tans[i]=xor32()%W;
    // h[i]=th[i]=(int)num[ans[i]].size();
    num[ans[i]].push_back(i);
    tnum[ans[i]].push_back(i);
  }
  score=val();
  while(true){
    time_t now=clock();
    if((double)(now-start)/CLOCKS_PER_SEC*1000>1950){
      break;
    }
    REP(i, N){
      tans[i]=xor32()%W;
      tnum[ans[i]].push_back(i);
    }
    int res=val();
    // DEBUG(res);
    if(res>score){
      score=res;
      REP(i, N){
        ans[i]=tans[i];
      }
      REP(i, W){
        num[i]=tnum[i];
      }
    }
  }
  REP(i, N){
    cout<<ans[i]<<'\n';
  }
  return 0;
}
