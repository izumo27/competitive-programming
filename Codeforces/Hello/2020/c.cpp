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
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

ll MOD;
constexpr int MAX=252525;
ll fact[MAX], fact_inv[MAX];


// 繰り返し二乗法
ll power(ll a, ll b){
	ll res=1;
	while(b>0){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

ll comb(ll n, ll r){
	return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  cin>>n>>MOD;
  fact[0]=1;
  // 階乗の計算
	REP(i, n) fact[i+1]=fact[i]*(i+1)%MOD;
	fact_inv[n]=power(fact[n], MOD-2);
  // 逆元の計算
	// FORR(i, 0, n) fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;
  ll ans=0;
  REP(i, n){
    ll tmp=0;
    tmp=(fact[i+1]*(n-i)%MOD)*fact[n-i-1]%MOD;
    ans=(ans+tmp*(n-i))%MOD;
    // DEBUG(ans);
  }
  cout<<ans<<'\n';
  return 0;
}
