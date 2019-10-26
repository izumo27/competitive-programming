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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

ll sum[114514];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll a[114514];
	cin>>n;
	REP(i, n){
		cin>>a[i];
	}
	sort(a, a+n);
	REP(i, n){
		sum[i+1]=sum[i]+a[i];
	}
	ll ans;
	if(n==2){
		ans=a[1]-a[0];
	}
	if(n==3){
		ans=max(2*a[2]-a[0]-a[1], a[1]+a[2]-2*a[0]);
	}
	else if(n&1){
		ans=max(2*(sum[n]-sum[n/2+1])-2*sum[n/2+1]+a[n/2]+a[n/2-1], 2*(sum[n]-sum[n/2])-a[n/2]-a[n/2+1]-2*sum[n/2]);
	}
	else{
		ans=2*(sum[n]-sum[n/2])-a[n/2]-2*sum[n/2]+a[n/2-1];
	}
	cout<<ans<<'\n';
	return 0;
}
