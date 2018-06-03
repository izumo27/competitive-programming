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
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, n;
	string x;
	cin>>a>>b>>n>>x;
	REP(i, n){
		if(x[i]=='S'){
			a=max(a-1, 0);
		}
		else if(x[i]=='C'){
			b=max(b-1, 0);
		}
		else{
			if(a>0 && b>0){
				a<b ? --b : --a;
			}
			else if(a>0){
				--a;
			}
			else if(b>0){
				--b;
			}
		}
	}
	cout<<a<<'\n';
	cout<<b<<'\n';
	return 0;
}
