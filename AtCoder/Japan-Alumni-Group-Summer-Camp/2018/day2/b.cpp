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

ll n;
int num[5]={5, 2, 5, 2, 5};

int dfs(int a, int cnt){
	if(a==5){
		return cnt<=n;
	}
	int res=0;
	REP(i, num[a]){
		res+=dfs(a+1, cnt);
		++cnt;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(10)<<fixed;
	cin>>n;
	if(n>=14){
		n=14;
	}
	cout<<dfs(0, 0)<<'\n';
	return 0;
}
