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

bool ng[334];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, NG;
	cin>>n;
	bool ok=true;
	REP(i, 3){
		cin>>NG;
		if(NG==n){
			ok=false;
			break;
		}
		ng[NG]=true;
	}
	REP(i, 100){
		if(n<=0){
			break;
		}
		if(n-3<0 || ng[n-3]){
			if(n-2<0 || ng[n-2]){
				if(ng[n-1]){
					ok=false;
				}
				else{
					--n;
				}
			}
			else{
				n-=2;
			}
		}
		else{
			n-=3;
		}
	}
	cout<<(ok && n<=0 ? "YES": "NO")<<'\n';
	return 0;
}
