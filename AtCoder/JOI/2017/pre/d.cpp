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

int dp[1<<20], sum[25][114514], num[25];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a[114514];
	cin>>n>>m;
	REP(i, n){
		cin>>a[i];
		--a[i];
		++num[a[i]];
		REP(j, m){
			sum[j][i+1]=sum[j][i];
		}
		++sum[a[i]][i+1];
	}
	REP(i, 1<<m){
		dp[i]=1e8;
	}
	dp[0]=0;
	REP(i, 1<<m){
		REP(j, m){
			if(i>>j&1){
				continue;
			}
			int cnt=0;
			REP(k, m){
				if(i>>k&1){
					cnt+=num[k];
				}
			}
			dp[i|1<<j]=min(dp[i|1<<j], dp[i]+num[j]-(sum[j][cnt+num[j]]-sum[j][cnt]));
			// DEBUG(dp[i|1<<j]);
			// DEBUG(sum[j][cnt+num[j]]-sum[j][cnt]);
		}
	}
	cout<<dp[(1<<m)-1]<<'\n';
	return 0;
}
