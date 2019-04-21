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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int cnt[252521], cnt2[252521];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin>>n>>s;
	int ans=1e9;
	FORR(i, 0, n){
		cnt[i]=cnt[i+1]+(s[i]=='.' ? 1 : 0);
		// DEBUG(cnt[i]);
	}
	REP(i, n){
		cnt2[i+1]=cnt2[i]+(s[i]=='#' ? 1 : 0);
	}
	REP(i, n){
		// DEBUG(ans);
		CHMIN(ans, cnt2[i]+cnt[i+1]);
		// DEBUG(cnt[i+1]);
		// DEBUG(cnt2[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
