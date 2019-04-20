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

int lb[364364], ub[364364];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n;
	string s;
	cin>>n>>s;
	if(n&1){
		cout<<":("<<'\n';
		return 0;
	}
	int x=0, y=0, z=0;
	REP(i, n){
		if(s[i]=='('){
			++x;
		}
		else if(s[i]==')'){
			++y;
		}
		else{
			++z;
		}
	}
	if(x>n/2 || y>n/2){
		cout<<":("<<'\n';
		return 0;
	}
	int cnt=0;
	string ans="";
	REP(i, n){
		if(s[i]=='('){
			ans+='(';
			++cnt;
		}
		else if(s[i]==')'){
			ans+=')';
			--cnt;
		}
		else{
			if(x<n/2){
				ans+='(';
				++x;
				++cnt;
			}
			else{
				ans+=')';
				--cnt;
			}
		}
		if(i!=n-1 && cnt<=0){
			cout<<":("<<'\n';
			return 0;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
