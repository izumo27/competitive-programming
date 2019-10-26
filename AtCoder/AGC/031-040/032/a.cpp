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

bool used[114];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, b[114];
	cin>>n;
	FOR(i, 1, n+1){
		cin>>b[i];
	}
	vi ans;
	FORR(i, 1, n+1){
		int cnt=1, cand=-1;
		FOR(j, 1, n+1){
			if(used[j]){
				continue;
			}
			if(cnt==b[j]){
				cand=j;
			}
			++cnt;
		}
		if(cand==-1){
			cout<<-1<<'\n';
			return 0;
		}
		ans.push_back(b[cand]);
		used[cand]=true;
	}
	FORR(i, 0, n){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
