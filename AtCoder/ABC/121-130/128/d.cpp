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

#define DEBUG(x) cout<<#x<<": "<<(x)<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, k;
	int v[60];
	cin>>n>>k;
	REP(i, n){
		cin>>v[i];
	}
	int ans=0;
	REP(i, k+1){
		REP(j, k-i+1){
			if(i+j>n){
				continue;
			}
			int x2[i+j];
			REP(j2, i){
				x2[j2]=v[j2];
			}
			int cnt=i-1;
			FORR(j2, n-j, n){
				x2[++cnt]=v[j2];
			}
			sort(x2, x2+i+j);
			int sum=0;
			REP(a, i+j){
				sum+=x2[a];
			}
			REP(a, min(k-i-j, i+j)){
				if(x2[a]>=0){
					break;
				}
				sum-=x2[a];
			}
			CHMAX(ans, sum);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
