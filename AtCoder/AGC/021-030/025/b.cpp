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

// const ll MOD=1000000007ll;
const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

ll fact[364364], fact_inv[364364];

ll mod_pow(ll a, ll b){
  ll res=1;
  while(b>0){
    if(b&1){
      res=res*a%MOD;
    }
    a=a*a%MOD;
    b>>=1;
  }
  return res;
}

ll comb(ll n, ll r){
  return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  ll k;
  cin>>n>>a>>b>>k;
  fact[0]=1;
  REP(i, n){
    fact[i+1]=fact[i]*(i+1)%MOD;
  }
  fact_inv[n]=mod_pow(fact[n], MOD-2);
  FORR(i, 0, n){
    fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;
  }
  ll ans=0;
  REP(i, n+1){
    if((k-i*a)%b==0){
      int j=(k-i*a)/b;
      if(j<=n){
        ans=(ans+comb(n, i)*comb(n, j)%MOD)%MOD;
        // DEBUG(i);
        // DEBUG(comb(n, i));
        // DEBUG(j);
        // DEBUG(comb(n, j));
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
