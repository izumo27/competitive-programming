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

typedef vector<vl> mat;

mat mul(mat &a, mat &b){
	int x=a.size(), y=b.size(), z=b[0].size();
	mat c(x, vl(z));
	REP(i, x)REP(k, y)REP(j, z){
		(c[i][j]+=(a[i][k]*b[k][j]%MOD))%=MOD;
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

ll dp[20][20][1<<16];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int h, r, g[20][20];
	cin>>h>>r;
	REP(i, r)REP(j, r) cin>>g[i][j];
	REP(i, r) dp[i][i][1<<i]=1;
	REP(i, r){
		REP(b, 1<<r){
			if(!(b>>i&1)) continue;
			REP(j, r){
				if(!(b>>j&1)) continue;
				REP(k, r){
					if((b>>k&1) || !g[j][k]) continue;
					(dp[i][k][b|(1<<k)]+=dp[i][j][b])%=MOD;
				}
			}
		}
	}
	mat a(r, vl(r));
	REP(i, r){
		REP(j, r){
			REP(b, 1<<r){
				(a[i][j]+=dp[i][j][b])%=MOD;
			}
		}
	}
	mat A=power(a, h);
	cout<<A[0][0]<<'\n';
	return 0;
}
