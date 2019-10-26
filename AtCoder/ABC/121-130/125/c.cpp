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

int gcd(int a, int b){
	if(b==0){
		return a;
	}
	return gcd(b, a%b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, a[114514];
	cin>>n;
	cin>>a[0];
	int cand[114514];
	cand[0]=a[0];
	REP(i, n-1){
		cin>>a[i+1];
		cand[i+1]=gcd(cand[i], a[i+1]);
	}
	int cand2[114514];
	cand2[n-1]=a[n-1];
	FORR(i, 0, n-1){
		cand2[i]=gcd(cand2[i+1], a[i]);
	}
	int ans=max(cand2[1], cand[n-2]);
	FOR(i, 1, n-1){
		CHMAX(ans, gcd(cand[i-1], cand2[i+1]));
	}
	cout<<ans<<'\n';
	return 0;
}
