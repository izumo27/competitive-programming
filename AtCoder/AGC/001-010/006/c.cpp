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

vi mul(vi &b, vi &a){
	int x=a.size();
	vi c(x);
	iota(ALL(c), 0);
	REP(i, x){
		c[i]=b[a[i]];
	}
	return c;
}

vi power(vi &a, ll k){
	int x=a.size();
	vi b(x);
	iota(ALL(b), 0);
	while(k>0){
		if(k&1){
			b=mul(b, a);
		}
		a=mul(a, a);
		k>>=1;
	}
	return b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, x[125252], m, a[125252], d[125252];
	ll k;
	cin>>n;
	cin>>x[0];
	REP(i, n-1){
		cin>>x[i+1];
		d[i]=x[i+1]-x[i];
	}
	cin>>m>>k;
	vi nxt(n-1);
	iota(ALL(nxt), 0);
	REP(i, m){
		cin>>a[i];
		--a[i];
		swap(nxt[a[i]-1], nxt[a[i]]);
	}
	vi res=power(nxt, k);
	ll ans[125252];
	ans[0]=x[0];
	REP(i, n-1){
		ans[i+1]=ans[i]+d[res[i]];
	}
	REP(i, n){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
