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
	ll c, d;
	cin>>c>>d;
	ll e=c, f=d;
	int cnt1=0;
	while(e>=170){
		e>>=1;
		++cnt1;
	}
	int cnt2=0;
	while(f>=170){
		f>>=1;
		++cnt2;
	}
	ll ans=0, tmp=140LL<<(cnt1);;
	if(e>=140){
		ans+=(170LL<<cnt1)-c;
		tmp=140LL<<(++cnt1);
	}
	while(tmp<d){
		ans+=(170LL<<(cnt1))-tmp;
		tmp=(140LL<<(++cnt1));
	}
	if(f>140){
		ans-=(170LL<<cnt2)-d;
	}
	cout<<ans<<'\n';
	return 0;
}
