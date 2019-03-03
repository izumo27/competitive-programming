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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const int MAX_N=1e9;
// const int MAX_SQRT_B=1e9;

int prime[MAX_N];
bool is_prime[MAX_N+1];
// bool is_prime_small[MAX_SQRT_B];

// bool is_prime(int n){
// 	for(int i=2; i*i<=n; ++i){
// 		if(n%i==0){
// 			return false;
// 		}
// 	}
// 	return n!=1;
// }

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

// 素因数分解
vector<pii> prime_factor(int n){
	vector<pii> res;
	for(int i=2; i*i<=n; ++i){
		if(n%i!=0){
			continue;
		}
		int num=0;
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

// エラトステネスの篩
// is_prime[i]=true⇔iが素数
int sieve(int n){
	int res=0;
	REP(i, n+1){
		is_prime[i]=true;
	}
	is_prime[0]=is_prime[1]=false;
	FOR(i, 2, n+1){
		if(is_prime[i]){
			prime[res++]=i;
			for(int j=2*i; j<=n; j+=i){
				is_prime[j]=false;
			}
		}
	}
	return res;
}

// [a, b)の整数についてエラトステネスの篩
// is_prime[i-a]=true⇔iが素数
void segment_sieve(int a, int b){
	for(int i=0; i*i<b; ++i){
		is_prime_small[i]=true;
	}
	REP(i, b-a){
		is_prime[i]=true;
	}
	for(int i=2; i*i<b; ++i){
		if(is_prime_small[i]){
			for(int j=2*i; j*j<b; j+=i){
				is_prime_small[j]=false;
			}
			for(int j=max(2, (a+i-1)/i)*i; j<b; j+=i){
				is_prime[j-a]=false;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
