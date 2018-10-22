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

int dp[1333][1333];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w, n, a[1333][1333];
	cin>>h>>w>>n;
	REP(i, h){
		REP(j, w){
			cin>>a[i][j];
		}
	}
	dp[0][0]=n-1;
	REP(i, h){
		REP(j, w){
			int tmp=dp[i][j]/2;
			if(a[i][j]){
				dp[i+1][j]+=tmp;
				dp[i][j+1]+=dp[i][j]-tmp;
			}
			else{
				dp[i+1][j]+=dp[i][j]-tmp;
				dp[i][j+1]+=tmp;
			}
		}
	}
	// REP(i, h){
	// 	REP(j, w){
	// 		cout<<dp[i][j]<<' ';
	// 	}
	// 	cout<<'\n';
	// }
	int now1=0, now2=0;
	while(now1<h && now2<w){
		if((dp[now1][now2]+a[now1][now2])&1){
			++now2;
		}
		else{
			++now1;
		}
	}
	cout<<now1+1<<' '<<now2+1<<'\n';
	return 0;
}
