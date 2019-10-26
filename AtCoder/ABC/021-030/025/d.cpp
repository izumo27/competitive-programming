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

const int MOD=1000000007;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int dp[1<<25];
int x[30], num[30];

// 立っているビット数を求める (int)
inline int bit_count(int n){
  n=((n>>1)&0x55555555)+(n&0x55555555);
  n=((n>>2)&0x33333333)+(n&0x33333333);
  n=((n>>4)&0x0f0f0f0f)+(n&0x0f0f0f0f);
  n=((n>>8)&0x00ff00ff)+(n&0x00ff00ff);
  n=((n>>16)&0x0000ffff)+(n&0x0000ffff);
  return n;
}

// 立っているビット数を求める (ll)
inline ll bit_count(ll n) {
  n=((n>>1)&0x5555555555555555LL)+(n&0x5555555555555555LL);
  n=((n>>2)&0x3333333333333333LL)+(n&0x3333333333333333LL);
  n=((n>>4)&0x0f0f0f0f0f0f0f0fLL)+(n&0x0f0f0f0f0f0f0f0fLL);
  n=((n>>8)&0x00ff00ff00ff00ffLL)+(n&0x00ff00ff00ff00ffLL);
  n=((n>>16)&0x00ff00ff00ff00ffLL)+(n&0x0000ffff0000ffffLL);
  n=((n>>32)&0x00000000ffffffffLL)+(n&0x00000000ffffffffLL);
  return n;
}

inline bool is_ok(int a, int b){
  int u=b/5, v=b%5;
  return !(a>>b&1) && !(0<v && v<4 && (a>>(b-1)&1)^(a>>(b+1)&1)) && !(0<u && u<4 && (a>>(b-5)&1)^(a>>(b+5)&1));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  REP(i, 25){
    num[i]=-1;
  }
  vi v;
  REP(i, 25){
    cin>>x[i];
    --x[i];
    if(x[i]>=0){
      num[x[i]]=i;
    }
    else{
      v.push_back(i);
    }
  }
  dp[0]=1;
  REP(i, 1<<25){
    if(!dp[i]){
      continue;
    }
    int sz=bit_count(i);
    if(num[sz]==-1){
      for(int w : v){
        if(is_ok(i, w)){
          int tmp=i|1<<w;
          dp[tmp]+=dp[i];
          if(dp[tmp]>=MOD){
            dp[tmp]-=MOD;
          }
        }
      }
    }
    else{
      if(is_ok(i, num[sz])){
        int tmp=i|1<<num[sz];
        dp[tmp]+=dp[i];
        if(dp[tmp]>=MOD){
          dp[tmp]-=MOD;
        }
      }
    }
  }
  cout<<dp[(1<<25)-1]<<'\n';
  return 0;
}
