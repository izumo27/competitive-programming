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

int factor[114], two, four, onefour, twofour, sevenfour;

// 素因数分解
void prime_factor(int n){
	for(int i=2; i*i<=n; ++i){
		if(n%i!=0){
			continue;
		}
		while(n%i==0){
			++factor[i];
			n/=i;
		}
	}
	if(n!=1){
		++factor[n];
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i, 2, n+1){
		prime_factor(i);
	}
	FOR(i, 2, n+1){
		if(factor[i]>=2){
			++two;
		}
		if(factor[i]>=4){
			++four;
		}
		if(factor[i]>=14){
			++onefour;
		}
		if(factor[i]>=24){
			++twofour;
		}
		if(factor[i]>=74){
			++sevenfour;
		}
	}
	int ans=0;
	// (1+74)
	ans+=sevenfour;
	// (1+2)*(1+24)
	ans+=twofour*(two-1);
	// (1+4)*(1+14)
	ans+=onefour*(four-1);
	// (1+2)*(1+4)*(1+4)
	ans+=four*(four-1)/2*(two-2);
	cout<<ans<<'\n';
	return 0;
}
