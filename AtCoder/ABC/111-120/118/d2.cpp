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

#define CHMIN(a, b) a=min((a), (b))
#define CHMAX(a, b) a=max((a), (b))

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int num[10]={0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[12525];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a[10];
	cin>>n>>m;
	REP(i, m){
		cin>>a[i];
	}
	sort(a, a+m);
	FOR(i, 1, n+1){
		dp[i]=-1;
	}
	REP(i, n+1){
		int ma=-1;
		REP(j, m){
			if(i>=num[a[j]]){
				CHMAX(ma, dp[i-num[a[j]]]);
			}
		}
		if(ma>=0){
			dp[i]=ma+1;
		}
	}
	int x=n;
	string ans="";
	while(x>0){
		FORR(i, 0, m){
			if(x>=num[a[i]] && dp[x-num[a[i]]]==dp[x]-1){
				ans+=to_string(a[i]);
				x-=num[a[i]];
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
