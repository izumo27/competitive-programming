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

int ans[1252][1252];
bool used[1252];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  cin>>n;
  if(~n&1){
    cout<<"No"<<'\n';
    return 0;
  }
  cout<<"Yes"<<'\n';
  REP(i, n){
    FOR(j, 1, n){
      ans[i][j]=i*n+j;
    }
    ans[i][0]=(i+1)*n;
  }
  FOR(i, 1, n/2+1){
    swap(ans[i][i], ans[n-i][n-i]);
  }
  REP(i, n){
    REP(j, n){
      cout<<ans[i][j]<<" \n"[j==n-1];
    }
  }
  return 0;
}
