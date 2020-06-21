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

ll num[252521];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[252521];
  cin>>n;
  REP(i, n){
    cin>>a[i];
    ++num[a[i]];
  }
  ll ans=0;
  REP(i, n+1){
    if(num[i]){
      ans+=num[i]*(num[i]-1)/2;
    }
  }
  REP(i, n){
    if(num[a[i]]>1){
      ll tmp=ans-num[a[i]]*(num[a[i]]-1)/2+(num[a[i]]-1)*(num[a[i]]-2)/2;
      cout<<tmp<<'\n';
    }
    else{
      cout<<ans<<'\n';
    }
  }
  return 0;
}