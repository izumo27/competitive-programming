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

int k;

bool is_ok(ll mid){
  int n[61], st=70;
  ll tmp=mid;
  FORR(i, 0, 61){
    n[i]=tmp%10;
    tmp/=10;
    if(n[i]>0){
      st=i;
    }
  }
  ll dp[62][2][2][10];
  REP(i, 62){
    REP(j, 2){
      REP(k, 2){
        REP(l, 10){
          dp[i][j][k][l]=0;
        }
      }
    }
  }
  dp[st][0][0][0]=1;
  FOR(i, st, 61){
    REP(j, 2){
      for(int x=0; x<=(j ? 9 : n[i]); ++x){
        dp[i+1][j || x<n[i]][x!=0][x]+=dp[i][j][0][0];
        dp[i+1][j || x<n[i]][1][x]+=dp[i][j][1][x];
        if(x>0){
          dp[i+1][j || x<n[i]][1][x]+=dp[i][j][1][x-1];
        }
        if(x+1<=9){
          dp[i+1][j || x<n[i]][1][x]+=dp[i][j][1][x+1];
        }
      }
    }
  }
  ll res=0;
  REP(i, 10){
    res+=dp[61][0][1][i]+dp[61][1][1][i];
    // if(mid==34){
    //   DEBUG(dp[61][0][i]);
    //   DEBUG(dp[61][1][i]);
    // }
  }
  // DEBUG(mid);
  // DEBUG(res);
  return res>=k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>k;
  ll lb=0, ub=1e18;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(is_ok(mid)){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  cout<<ub<<'\n';
  return 0;
}
