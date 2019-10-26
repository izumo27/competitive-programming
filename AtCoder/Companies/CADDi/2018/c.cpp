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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

// 素因数分解
vector<pll> prime_factor(ll n){
  vector<pll> res;
  for(ll i=2; i*i<=n; ++i){
    if(n%i!=0){
      continue;
    }
    ll num=0;
    while(n%i==0){
      ++num;
      n/=i;
    }
    res.push_back(pii(i, num));
  }
  if(n!=1){
    res.push_back(pii(n, 1));
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, p;
  cin>>n>>p;
  if(n==1){
    cout<<p<<'\n';
    return 0;
  }
  vector<pll> x=prime_factor(p);
  ll ans=1;
  for(auto &y : x){
    for(ll i=0; i<y.second/n; ++i){
      ans*=y.first;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
