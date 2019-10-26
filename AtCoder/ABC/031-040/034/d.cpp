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

int n, k, w[1333], p[1333];

bool is_ok(double x){
	double a[1333];
	REP(i, n){
		a[i]=(p[i]-x)*w[i];
	}
	sort(a, a+n, greater<double>());
	double tmp=0;
	REP(i, k){
		tmp+=a[i];
	}
	return tmp>=0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	REP(i, n){
		cin>>w[i]>>p[i];
	}
	double lb=0, ub=100;
	while(ub-lb>EPS){
		double mid=(lb+ub)/2;
		if(is_ok(mid)){
			lb=mid;
		}
		else{
			ub=mid;
		}
	}
	cout<<fixed<<setprecision(10)<<lb<<'\n';
	return 0;
}
