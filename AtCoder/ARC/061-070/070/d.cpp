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

int n, k;
int a[5252], dp[5252];

bool is_need(int mid){
	REP(i, k){
		dp[i]=0;
	}
	int cnt=0;
	dp[0]=1;
	REP(i, n){
		if(i==mid){
			continue;
		}
		FORR(j, 0, k){
			if(dp[j] && j+a[i]<k){
				dp[j+a[i]]=1;
			}
		}
	}
	// DEBUG(mid);
	// REP(i, k){
	// 	DEBUG(dp[cnt][i]);
	// }
	FOR(i, max(0, k-a[mid]), k){
		if(dp[i]){
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	cin>>n>>k;
	REP(i, n){
		cin>>a[i];
	}
	if(n==1){
		cout<<(a[0]>=k ? 0 : 1)<<'\n';
		return 0;
	}
	sort(a, a+n);
	int lb=-1, ub=n;
	while(ub-lb>1){
		int mid=(lb+ub)/2;
		if(is_need(mid)){
			ub=mid;
		}
		else{
			lb=mid;
		}
	}
	cout<<ub<<'\n';
	return 0;
}
