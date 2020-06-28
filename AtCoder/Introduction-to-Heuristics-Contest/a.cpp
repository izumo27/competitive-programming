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

constexpr int INF=1e9;
int D, c[30], s[400][30];
int ans[400];
int tans[400];

// 乱数
unsigned int xor32() {
  static unsigned int x = 2463534242;
  x = x ^ (x << 13); x = x ^ (x >> 17);
  return x = x ^ (x << 15);
}

// スコアを全部計算
int val(){
  int last[30];
  REP(i, 26){
    last[i]=0;
  }
  int res=0;
  FOR(i, 1, D+1){
    last[tans[i]]=i;
    res+=s[i-1][tans[i]];
    REP(j, 26){
      res-=c[j]*(i-last[j]);
    }
  }
  return res;
}

// スコアを差分計算
int diff(){
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  time_t start=clock();

  // 入力
  cin>>D;
  REP(i, 26){
    cin>>c[i];
  }
  REP(i, D){
    REP(j, 26){
      cin>>s[i][j];
    }
  }

  // 初期解
  int score=0;
  int last[30];
  REP(i, 26){
    last[i]=0;
  }
  REP(i, D){
    int ma=0, idx=-1;
    REP(j, 26){
      if(ma<s[i][j]+c[j]*(i+1-last[j])){
        ma=s[i][j]+c[j]*(i+1-last[j]);
        idx=j;
      }
      score-=c[j]*(i+1-last[j]);
    }
    ans[i]=idx;
    tans[i]=ans[i];

    score+=s[i][idx]+c[idx]*(i+1-last[idx]);
    last[idx]=i;
  }
  // DEBUG(score);

  while(true){
    time_t end=clock();
    if((double)(end-start)/CLOCKS_PER_SEC*1000>1980){
      break;
    }
    int d1=xor32()%D;
    int d2=max(0, min(D-1, d1-2+(int)xor32()%5));
    if(d1==d2){
      continue;
    }
    swap(tans[d1], tans[d2]);
    int tmp=val();
    if(tmp>score){
      score=tmp;
      swap(ans[d1], ans[d2]);
    }
  }
  // DEBUG(score);
  REP(i, D){
    cout<<ans[i]+1<<'\n';
  }
  return 0;
}
