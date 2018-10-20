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
	int q;
	ll a, b, c;
	cin>>q;
	REP(i, q){
		bool ok=false;
		cin>>a>>b>>c;
		if(a&1){
			ll d=b*10+c;
			if(d>=100){
				if(b>=10){
					b-=10;
					if(b&1){
						if(c>=10 && c%2==0){
							ok=true;
						}
					}
					else if(c%2==0){
						ok=true;
					}
				}
				else{
					c-=100-b*10;
					if(c>=0 && c%2==0){
						ok=true;
					}
				}
			}
		}
		else{
			if(b&1){
				if(c>=10 && c%2==0){
					ok=true;
				}
			}
			else if(c%2==0){
				ok=true;
			}
		}
		cout<<(ok ? "Yes" : "No")<<'\n';
	}
	return 0;
}
