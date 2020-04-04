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

// 約数を求める
vl divisor(ll n){
  vl res;
  for(ll i=1; i*i<=n; ++i){
    if(n%i==0){
      res.push_back(i);
      if(i!=n/i){
        res.push_back(n/i);
      }
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  ll n;
  cin>>n;
  vl a=divisor(n);
  vl b=divisor(n-1);
  sort(ALL(a));sort(ALL(b));
  vl c;
  merge(ALL(a), ALL(b), back_inserter(c));
  c.erase(unique(ALL(c)), c.end());
  ll ans=0;
  int sz=c.size();
  REP(i, sz){
    ll tmp=c[i];
    ll cur=n;
    if(tmp!=1){
      while(cur%tmp==0){
        cur/=tmp;
        if(cur==0){
          break;
        }
      }
    }
    cur%=tmp;
    if(cur==1){
      ++ans;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
