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

int dp[20][114];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int d, g, p[20], c[20];
	cin>>d>>g;
	REP(i, d){
		cin>>p[i]>>c[i];
	}
	REP(i, d){
		REP(j, p[i]-1){
			dp[i][j]=100*(i+1)*(j+1);
		}
		dp[i][p[i]-1]=100*(i+1)*(p[i])+c[i];
	}
	int m[20];
	REP(i, d){
		m[i]=dp[i][p[i]-1];
	}
	int ans=114514;
	REP(i, 1<<d){
		int tmp1=0, tmp2=-1, tmpg=g;
		REP(j, d){
			if(i & (1<<j)){
				tmpg-=m[j];
				tmp1+=p[j];
			}
			else{
				tmp2=j;
			}
		}
		if(tmpg>0 && tmp2!=-1){
			REP(j, p[tmp2]){
				if(dp[tmp2][j]>=tmpg){
					tmp1+=j+1;
					tmpg-=dp[tmp2][j];
					break;
				}
			}
		}
		if(tmpg<=0){
			ans=min(ans, tmp1);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
