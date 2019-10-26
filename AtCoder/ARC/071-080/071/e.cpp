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
	string s, t;
	int q, a, b, c, d;
	cin>>s>>t>>q;
	int snum[114514], tnum[114514];
	snum[0]=0;
	REP(i, s.size()){
		snum[i+1]+=snum[i]+(s[i]=='A' ? 1 : 2);
	}
	tnum[0]=0;
	REP(i, t.size()){
		tnum[i+1]+=tnum[i]+(t[i]=='A' ? 1 : 2);
	}
	REP(i, q){
		cin>>a>>b>>c>>d;
		cout<<((snum[b]-snum[a-1])%3==(tnum[d]-tnum[c-1])%3 ? "YES" : "NO")<<'\n';
	}
	return 0;
}
