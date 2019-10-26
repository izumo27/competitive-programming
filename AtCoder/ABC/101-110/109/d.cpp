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
	int h, w, a[514][514];
	cin>>h>>w;
	REP(i, h){
		REP(j, w){
			cin>>a[i][j];
		}
	}
	int cnt=0;
	int ans[514514][4];
	REP(i, h){
		REP(j, w){
			if(a[i][j]&1){
				// DEBUG(i);
				// DEBUG(j);
				// DEBUG(cnt);
				if(j!=w-1){
					++a[i][j+1];
					ans[cnt][0]=i;
					ans[cnt][1]=j;
					ans[cnt][2]=i;
					ans[cnt][3]=j+1;
					++cnt;
				}
				else if(i!=h-1){
					++a[i+1][j];
					ans[cnt][0]=i;
					ans[cnt][1]=j;
					ans[cnt][2]=i+1;
					ans[cnt][3]=j;
					++cnt;
				}
			}
		}
	}
	cout<<cnt<<'\n';
	if(cnt){
		REP(i, cnt){
			cout<<ans[i][0]+1<<' '<<ans[i][1]+1<<' '<<ans[i][2]+1<<' '<<ans[i][3]+1<<'\n';
		}
	}
	return 0;
}
