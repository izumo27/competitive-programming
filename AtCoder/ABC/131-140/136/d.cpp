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

int ans[125252];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	string s;
	cin>>s;
	int n=s.size();
	int odd=0, even=0;
	bool flag=true;
	REP(i, n){
		if(flag && s[i]=='L'){
			if(i&1){
				ans[i-1]+=even;
				ans[i]+=odd+1;
			}
			else{
				ans[i-1]+=odd;
				ans[i]+=even+1;
			}
			flag=false;
			odd=0;
			even=0;
		}
		else if(s[i]=='R'){
			flag=true;
			if(i&1){
				++odd;
			}
			else{
				++even;
			}
		}
	}
	// REP(i, n){
	// 	cout<<ans[i]<<" \n"[i==n-1];
	// }
	odd=0;
	even=0;
	flag=true;
	FORR(i, 0, n){
		if(flag && s[i]=='R'){
			if((n-1-i)&1){
				ans[i]+=odd;
				ans[i+1]+=even-1;
			}
			else{
				ans[i]+=even;
				ans[i+1]+=odd-1;
			}
			flag=false;
			odd=0;
			even=0;
		}
		else if(s[i]=='L'){
			flag=true;
			if((n-1-i)&1){
				++odd;
			}
			else{
				++even;
			}
		}
	}
	REP(i, n){
		cout<<ans[i]<<" \n"[i==n-1];
	}
	return 0;
}
