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

int n;
ll x, sum;
ll b[125252], l[125252], u[125252];
pair<ll, int> a[125252];

bool is_ok(ll mid){
	ll k=mid/x, k2=mid%x, tmp=0;
	FORR(i, max(0ll, n-k), n){
		tmp+=a[i].first;
	}
	ll ma=0;
	FORR(i, 0, max(0ll, n-k)){
		int j=a[i].second;
		CHMAX(ma, u[j]*k2-(u[j]-l[j])*b[j]);
		CHMAX(ma, l[j]*k2);
	}
	if(tmp+ma>=sum){
		return true;
	}
	ll mi=1e12;
	FORR(i, max(0ll, n-k), n){
		int j=a[i].second;
		CHMIN(mi, u[j]*(x-k2));
		CHMIN(mi, u[j]*x-l[j]*k2-(u[j]-l[j])*b[j]);
	}
	tmp-=mi;
	if(n-k>0){
		tmp+=a[n-k-1].first;
	}
	return tmp>=sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	cin>>n>>x;
	REP(i, n){
		cin>>b[i]>>l[i]>>u[i];
	}
	sum=0;
	REP(i, n){
		sum+=b[i]*l[i];
	}
	REP(i, n){
		a[i]=make_pair(u[i]*x-(u[i]-l[i])*b[i], i);
	}
	sort(a, a+n);
	ll lb=-1, ub=1e12;
	while(ub-lb>1){
		ll mid=(lb+ub)/2;
		if(is_ok(mid)){
			ub=mid;
		}
		else{
			lb=mid;
		}
	}
	cout<<ub<<'\n';
	return 0;
}
