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

int ans[50];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(10)<<fixed;
	ll a, b;
	cin>>a>>b;
	if(a&1){
		ans[0]=((b-a)%4>=2 ? 0 : 1);
	}
	else{
		ll tmp=(b-a)%4;
		ans[0]=(tmp==0 || tmp==3 ? 0 : 1);
	}
	ll mask=2;
	FOR(i, 1, 40){
		mask<<=1;
		ll c=a%mask, d=b%mask;
		if(c<mask/2){
			ans[i]=(d<mask/2 || d&1 ? 0 : 1);
		}
		else{
			if(c&1){
				ans[i]=(d>=mask/2 && ~d&1 ? 0 : 1);
			}
			else{
				ans[i]=(d<mask/2 || d&1 ? 0 : 1);
			}
		}
	}
	ll res=0;
	FORR(i, 0, 40){
		res<<=1;
		res+=ans[i];
	}
	cout<<res<<'\n';
	return 0;
}
