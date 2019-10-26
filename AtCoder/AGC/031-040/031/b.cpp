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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const int MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int dp[252521];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(10)<<fixed;
  int n, c[252521];
  cin>>n;
  REP(i, n){
    cin>>c[i];
  }
  vi cc;
  cc.push_back(c[0]);
  REP(i, n-1){
    if(c[i]!=c[i+1]){
      cc.push_back(c[i+1]);
    }
  }
  n=(int)cc.size();
  dp[cc[0]]=1;
  FOR(i, 1, n){
    dp[cc[i]]=(dp[cc[i]]+dp[cc[i-1]])%MOD;
  }
  cout<<dp[cc[n-1]]<<'\n';
  return 0;
}
