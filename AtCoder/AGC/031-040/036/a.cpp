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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	ll s;
	cin>>s;
	ll lb=0, ub=1e9;
	while(ub-lb>1){
		ll mid=(lb+ub)/2;
		if(mid*mid>s){
			ub=mid;
		}
		else{
			lb=mid;
		}
	}
	if(abs(s-ub*ub)>abs(s-(ub+1)*(ub+1))){
		++ub;
	}
	ll a=abs(s-ub*ub);
	cout<<0<<' '<<0<<' ';
	cout<<ub<<' '<<1<<' ';
	cout<<a<<' '<<ub<<'\n';
	// DEBUG(ub*ub-a-s);
	return 0;
}
