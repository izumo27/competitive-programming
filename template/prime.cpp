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
#define CHMAX(a, b) a=min((a), (b))

const int MOD=1000000007;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

vector<int> Eratosthenes(int n) {
	vector<bool> num(n, true);
	vector<int> prime;
	num[0]=false;
	for(int i=0; i*i<n; ++i){
		if(num[i]){
			for(int j=2; (i+1)*j<=n; ++j) {
				num[(i+1)*j-1]=false;
			}
		}
	}
	for(int i=0; i<n; ++i) {
		if(num[i]){
			prime.push_back(i+1);
		}
	}
	return prime;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
