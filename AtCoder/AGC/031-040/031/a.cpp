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

ll power(ll a, ll b){
	ll res=1;
	while(b>0){
		if(b&1){
			res=res*a%MOD;
		}
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

int cnt[30];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(10)<<fixed;
	int n;
	string s;
	cin>>n>>s;
	REP(i, n){
		++cnt[s[i]-'a'];
	}
	ll ans=1;
	REP(i, 26){
		if(cnt[i]==1){
			ans=(ans*2)%MOD;
		}
		else{
			ans=(ans*(cnt[i]+1))%MOD;
		}
	}
	ans=(ans-1+MOD)%MOD;
	cout<<ans<<'\n';
	return 0;
}
