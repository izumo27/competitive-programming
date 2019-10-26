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

int n;
ll W, v[252], w[252];
pll vw[1<<16], vw2[1<<16], vw3[1<<16];

ll dp[252][214514];

int binary_seach(int x, int c){
	int l=0, r=c;
	while(r-l>1){
		int i=(l+r)/2;
		if(vw[x].first+vw3[i].first>W){
			r=i;
		}
		else{
			l=i;
		}
	}
	return l;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>W;
	ll a=0ll;
	REP(i, n){
		cin>>v[i]>>w[i];
		a=max(a, v[i]);
	}
	if(n<=30){
		int m=n/2;
		ll tmpv, tmpw;
		int cnt=0;
		REP(i, 1<<m){
			tmpv=0ll;
			tmpw=0ll;
			REP(j, m){
				if((i>>j)&1){
					tmpv+=v[j];
					tmpw+=w[j];
				}
			}
			if(tmpw<=W){
				vw[cnt++]=pll(tmpw, tmpv);
			}
		}
		int m2=n-m;
		int cnt2=0;
		REP(i, 1<<m2){
			tmpv=0ll;
			tmpw=0ll;
			REP(j, m2){
				if((i>>j)&1){
					tmpv+=v[m+j];
					tmpw+=w[m+j];
				}
			}
			if(tmpw<=W){
				vw2[cnt2++]=pll(tmpw, tmpv);
			}
		}
		sort(vw2, vw2+cnt2);
		vw3[0]=vw2[0];
		int cnt3=1;
		tmpv=vw2[0].second;
		FOR(i, 1, cnt2){
			if(tmpv<vw2[i].second){
				vw3[cnt3++]=vw2[i];
				tmpv=vw2[i].second;
			}
		}
		ll ans=0;
		REP(i, cnt){
			int j=binary_seach(i, cnt3);
			ans=max(ans, vw[i].second+vw3[j].second);
		}
		cout<<ans<<'\n';
		return 0;
	}
	else{
		if(a<=1000ll){
			REP(i, 200001){
				dp[0][i]=1e18;
			}
			dp[0][0]=0;
			REP(i, n){
				REP(j, 200001){
					if(j<v[i]){
						dp[i+1][j]=dp[i][j];
					}
					else{
						dp[i+1][j]=min(dp[i][j], dp[i][j-v[i]]+w[i]);
					}
				}
			}
			int ans=0;
			FORR(i, 0, 200001){
				if(dp[n][i]<=W){
					cout<<i<<'\n';
					return 0;
				}
			}
		}
		else{
			REP(i, n){
				REP(j, W+1){
					if(j<w[i]){
						dp[i+1][j]=dp[i][j];
					}
					else{
						dp[i+1][j]=max(dp[i][j], dp[i][j-w[i]]+v[i]);
					}
				}
			}
			cout<<dp[n][W]<<'\n';
		}
	}
	return 0;
}
