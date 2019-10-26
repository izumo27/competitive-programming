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

ll gcd(ll a, ll b){
  if(b==0){
    return a;
  }
  return gcd(b, a%b);
}

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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin>>n>>m;
  if(n==1){
    cout<<m<<'\n';
    return 0;
  }
  ll ans=0;
  vl a=divisor(m);
  REP(i, a.size()){
    if(a[i]*n<=m){
      ans=max(ans, a[i]);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
