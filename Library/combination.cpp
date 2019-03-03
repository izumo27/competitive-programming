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

template<typename T> inline void CHMAX(T& a, const T b) {if(a>b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a<b) a=b;}

// const ll MOD=1000000007ll;
const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const int MAX_N=514514;

ll fact[MAX_N], fact_inv[MAX_N];

ll power(ll a, ll b){
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

void init_comb(int n){
	fact[0]=1;
	REP(i, n){
		fact[i+1]=fact[i]*(i+1)%MOD;
	}
	fact_inv[n]=power(fact[n], MOD-2);
	FORR(i, 0, n){
		fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;
	}
	return;
}

// iの逆元も求める場合
// ll inv[MAX_N];
// void init_comb(int n){
//     fact[0]=fact[1]=1;
//     fact_inv[0]=fact_inv[1]=1;
//     inv[1]=1;
//     FOR(i, 2, n+1){
//         fact[i]=fact[i-1]*i%MOD;
//         inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
//         fact_inv[i]=fact_inv[i-1]*inv[i]%MOD;
//     }
// }

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
