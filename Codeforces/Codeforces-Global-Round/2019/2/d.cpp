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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, q;
	ll s[114514], l, r;
	cin>>n;
	REP(i, n){
		cin>>s[i];
	}
	sort(s, s+n);
	ll mi=s[0], ma=s[n-1];
	ll a[114514], sum[114514];
	sum[0]=0;
	REP(i, n-1){
		a[i]=s[i+1]-s[i]-1;
	}
	sort(a, a+n-1);
	REP(i, n-1){
		sum[i+1]=sum[i]+a[i];
	}
	cin>>q;
	REP(i, q){
		cin>>l>>r;
		ll d=r-l;
		ll ans=ma+d-mi+1;
		int tmp=upper_bound(a, a+n-1, d)-a;
		// DEBUG(tmp);
		// DEBUG(sum[n-1]-sum[tmp]);
		ans-=sum[n-1]-sum[tmp]-d*(n-1-tmp);
		cout<<ans<<" \n"[i==q-1];
	}
	return 0;
}
