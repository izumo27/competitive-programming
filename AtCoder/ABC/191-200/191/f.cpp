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

// constexpr ll MOD=1000000007ll;
constexpr ll MOD=998244353ll;
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

vi x[2525];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[2525];
  cin>>n;
  REP(i, n){
    cin>>a[i];
  }
  sort(a, a+n);
  REP(i, n){
    x[i]=divisor(a[i]);
  }
  map<int, int> mp;
  REP(i, n){
    for(auto& y : x[i]){
      if(mp.find(y)==mp.end()){
        mp[y]=a[i];
      }
      else{
        int tmp=mp[y];
        mp[y]=gcd(tmp, a[i]);
      }
    }
  }
  int ans=0;
  for(auto& [y, z] : mp){
    // DEBUG(y);DEBUG(z);
    if(y==z){
      if(y<=a[0]){
        ++ans;
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
