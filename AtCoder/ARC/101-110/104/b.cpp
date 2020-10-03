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

int cnt[5252][4];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  string s;
  cin>>n>>s;
  REP(i, n){
    REP(j, 4){
      cnt[i+1][j]=cnt[i][j];
    }
    if(s[i]=='A'){
      ++cnt[i+1][0];
    }
    if(s[i]=='T'){
      ++cnt[i+1][1];
    }
    if(s[i]=='C'){
      ++cnt[i+1][2];
    }
    if(s[i]=='G'){
      ++cnt[i+1][3];
    }
  }
  int ans=0;
  REP(i, n){
    FOR(j, i+1, n){
      if(cnt[j+1][0]-cnt[i][0]!=cnt[j+1][1]-cnt[i][1] || cnt[j+1][2]-cnt[i][2]!=cnt[j+1][3]-cnt[i][3]){
        continue;
      }
      ++ans;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
