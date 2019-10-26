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

int num1[114514], num2[114514];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, v;
	cin>>n;
	REP(i, n){
		cin>>v;
		if(i&1){
			++num1[v];
		}
		else{
			++num2[v];
		}
	}
	int ma1=0, ma2=0, ma3=0, ma4=0, a, b;
	REP(i, 114514){
		if(ma1<num1[i]){
			a=i;
			ma3=ma1;
			ma1=num1[i];
		}
		else{
			ma3=max(ma3, num1[i]);
		}
		if(ma2<num2[i]){
			b=i;
			ma4=ma2;
			ma2=num2[i];
		}
		else{
			ma4=max(ma4, num2[i]);
		}
	}
	if(a!=b){
		cout<<n-ma1-ma2<<'\n';
	}
	else{
		cout<<min(n-ma1-ma4, n-ma3-ma2)<<'\n';
	}
	return 0;
}
