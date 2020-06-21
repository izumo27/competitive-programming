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

int num[3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  string A;
  int a[1252521];
  cin>>n>>A;
  int one=0, two=0;
  REP(i, n){
    a[i]=A[i]-'1';
    ++num[a[i]];
    if(a[i]==1){
      one+=(n-1==(i|(n-1-i)));
    }
    if(a[i]==2){
      two+=(n-1==(i|(n-1-i)));
    }
  }
  // DEBUG(one);DEBUG(two);
  if(one&1){
    cout<<1<<'\n';
    return 0;
  }
  if(num[0] && num[1] && num[2]){
    cout<<0<<'\n';
    return 0;
  }
  cout<<(two&1 ? 2 : 0)<<'\n';
  return 0;
}