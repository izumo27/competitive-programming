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
	int k;
	ll a, b;
	cin>>k>>a>>b;
	if(b-a<=1 || k<a-1){
		cout<<k+1<<'\n';
		return 0;
	}
	ll ans=0;
	if(a&1){
		if(k&1){
			ans=a+(b-a)*(k-1-(a-1))/2+1;
		}
		else{
			ans=a+(b-a)*(k-(a-1))/2;
		}
	}
	else{
		if(k&1){
			ans=a+(b-a)*(k-(a-1))/2;
		}
		else{
			ans=a+(b-a)*(k-1-(a-1))/2+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}