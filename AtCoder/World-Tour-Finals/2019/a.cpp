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
	int n, k, a[60];
	cin>>n>>k;
	REP(i, n){
		cin>>a[i];
	}
	vi ans;
	int pre=-1;
	REP(i, k+1){
		int mi=200, idx=0;
		REP(j, n){
			if(j!=pre && a[j]<mi){
				if(a[j]==0){
					cout<<-1<<'\n';
					return 0;
				}
				mi=a[j];
				idx=j;
			}
		}
		REP(j, n){
			if(j!=pre && j!=idx){
				ans.push_back(j+1);
				--a[j];
			}
		}
		ans.push_back(idx+1);
		--a[idx];
		pre=idx;
	}
	cout<<ans.size()<<'\n';
	REP(i, ans.size()){
		cout<<ans[i]<<' ';
	}
	return 0;
}
