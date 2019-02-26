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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, q, a[2525];
	cin>>n>>k>>q;
	REP(i, n){
		cin>>a[i];
	}
	int ans=MOD;
	REP(i, n){
		int mi=a[i];
		vi cand;
		int idx=0;
		while(idx<n){
			vi v;
			int cnt=0;
			for(;;){
				int tmp=a[idx++];
				if(tmp>=mi){
					v.push_back(tmp);
					++cnt;
				}
				if(tmp<mi || idx==n){
					if(cnt-k+1>0){
						sort(ALL(v));
						REP(j, cnt-k+1){
							cand.push_back(v[j]);
						}
					}
					break;
				}
			}
		}
		if(cand.size()>=q){
			sort(ALL(cand));
			CHMIN(ans, cand[q-1]-mi);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
