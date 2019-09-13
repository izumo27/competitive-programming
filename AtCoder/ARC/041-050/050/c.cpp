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

ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}
	return gcd(b, a%b);
}

typedef vector<vl> mat;
ll mod;

mat mul(mat &a, mat &b){
	int x=a.size(), y=b.size(), z=b[0].size();
	mat c(x, vl(z));
	REP(i, x)REP(k, y)REP(j, z){
		(c[i][j]+=(a[i][k]*b[k][j]%mod))%=mod;
	}
	return c;
}

mat power(mat a, ll n){
	int x=a.size();
	mat b(x, vl(x));
	REP(i, x){
		b[i][i]=1;
	}
	while(n>0){
		if(n&1){
			b=mul(b, a);
		}
		a=mul(a, a);
		n>>=1;
	}
	return b;
}

ll power(ll a, ll b){
	ll x=a, res=1, p=b;
	while(p>0){
		if(p&1) (res*=x)%=mod;
		(x*=x)%=mod;
		p>>=1;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	ll a, b;
	cin>>a>>b>>mod;
	ll c=gcd(a, b);
	mat C(2, vl(2));
	C[0][0]=power(10, c);C[0][1]=1;
	C[1][0]=0;C[1][1]=1;
	mat D=power(C, b/c);

	mat A(2, vl(2));
	A[0][0]=10;A[0][1]=1;
	A[1][0]=0;A[1][1]=1;
	mat B=power(A, a);

	ll ans=B[0][1]*D[0][1]%mod;
	// DEBUG(B[0][1]);
	// DEBUG(C[0][1]);
	cout<<ans<<'\n';
	return 0;
}
