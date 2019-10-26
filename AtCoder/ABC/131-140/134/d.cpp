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

// 約数を求める
vi divisor(int n){
  vi res;
  for(int i=1; i*i<=n; ++i){
    if(n%i==0){
      res.push_back(i);
      if(i!=n/i){
        res.push_back(n/i);
      }
    }
  }
  return res;
}

int cnt[252525];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[252525];
  cin>>n;
  FOR(i, 1, n+1){
    cin>>a[i];
  }
  vi ans;
  FORR(i, 1, n+1){
    if((cnt[i]&1)==a[i]){
      continue;
    }
    ans.push_back(i);
    vi v=divisor(i);
    for(auto &x : v){
      ++cnt[x];
    }
  }
  int sz=ans.size();
  cout<<sz<<'\n';
  for(auto &x : ans){
    cout<<x<<'\n';
  }
  return 0;
}
