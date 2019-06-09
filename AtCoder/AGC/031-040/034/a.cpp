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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, a, b, c, d;
	string s;
	cin>>n>>a>>b>>c>>d>>s;
	--a;
	--b;
	--c;
	--d;
	if(c==d){
		cout<<"No"<<'\n';
		return 0;
	}
	if(c<d){
		bool ok=true, ng=false;
		FOR(i, a, c+1){
			if(ng && s[i]=='#'){
				ok=false;
				break;
			}
			if(s[i]=='#'){
				ng=true;
			}
			else{
				ng=false;
			}
		}
		ng=false;
		FOR(i, b, d+1){
			if(ng && s[i]=='#'){
				ok=false;
				break;
			}
			if(s[i]=='#'){
				ng=true;
			}
			else{
				ng=false;
			}
		}
		cout<<(ok ? "Yes" : "No")<<'\n';
		return 0;
	}
	bool ok=true, ng=false;
	FOR(i, a, c+1){
		if(ng && s[i]=='#'){
			ok=false;
			break;
		}
		if(s[i]=='#'){
			ng=true;
		}
		else{
			ng=false;
		}
	}
	ng=false;
	FOR(i, b, d+1){
		if(ng && s[i]=='#'){
			ok=false;
			break;
		}
		if(s[i]=='#'){
			ng=true;
		}
		else{
			ng=false;
		}
	}
	if(!ok){
		cout<<"No"<<'\n';
		return 0;
	}
	ok=false;
	int cnt=0;
	FOR(i, b-1, min(n, d+2)){
		if(cnt==2 && s[i]=='.'){
			ok=true;
			break;
		}
		if(s[i]=='.'){
			++cnt;
		}
		else{
			cnt=0;
		}
	}
	cout<<(ok ? "Yes" : "No")<<'\n';
	return 0;
}
