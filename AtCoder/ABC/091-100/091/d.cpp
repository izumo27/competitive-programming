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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a[214514], b[214514], c[214514], d[214514];
	cin>>n;
	REP(i, n){
		cin>>a[i];
	}
	REP(i, n){
		cin>>b[i];
	}
	int ans=0;
	REP(i, 29){
		int bit=1<<i, bit2=bit<<1;
		REP(j, n){
			c[j]=a[j]&(bit2-1);
			d[j]=b[j]&(bit2-1);
		}
		sort(d, d+n);
		int cnt=0;
		REP(j, n){
			cnt+=lower_bound(d, d+n, bit2-c[j])-lower_bound(d, d+n, bit-c[j]);
			cnt+=lower_bound(d, d+n, (bit2<<1)-c[j])-lower_bound(d, d+n, 3*bit-c[j]);
		}
		if(cnt&1){
			ans^=bit;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
