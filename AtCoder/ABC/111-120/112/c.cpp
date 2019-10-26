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
	int n;
	ll x[114], y[114], h[114];
	cin>>n;
	REP(i, n){
		cin>>x[i]>>y[i]>>h[i];
	}
	for(ll c1=0; c1<=100; ++c1){
		for(ll c2=0; c2<=100; ++c2){
			bool f=false, ok=true;
			ll H=1e18;
			REP(i, n){
				if(f){
					if(h[i]==0){
						if(H>abs(x[i]-c1)+abs(y[i]-c2)){
							ok=false;
							i=n;
						}
					}
					else if(H!=h[i]+abs(x[i]-c1)+abs(y[i]-c2)){
						ok=false;
						i=n;
					}
				}
				else{
					if(h[i]==0){
						H=min(H, abs(x[i]-c1)+abs(y[i]-c2));
					}
					else if(H<h[i]+abs(x[i]-c1)+abs(y[i]-c2)){
						ok=false;
						i=n;
					}
					else{
						H=h[i]+abs(x[i]-c1)+abs(y[i]-c2);
						f=true;
					}
				}
			}
			if(ok && H>=1){
				cout<<c1<<' '<<c2<<' '<<H<<'\n';
				return 0;
			}
		}
	}
	return 0;
}
