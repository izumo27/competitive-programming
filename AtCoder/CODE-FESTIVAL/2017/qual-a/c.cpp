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

int alf[30];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	char a;
	cin>>h>>w;
	REP(i, h){
		REP(j, w){
			cin>>a;
			++alf[a-'a'];
		}
	}
	int cnt=0, cnt2=0;
	REP(i, 26){
		if(alf[i]%2!=0){
			++cnt;
		}
		if(alf[i]%4!=0){
			++cnt2;
		}
	}
	bool ok=false;
	if(h&1 && w&1){
		if(cnt2<=(h+w)/2 && cnt==1){
			ok=true;
		}
	}
	else if(h&1){
		if(cnt2<=w/2 && cnt==0){
			ok=true;
		}
	}
	else if(w&1){
		if(cnt2<=h/2 && cnt==0){
			ok=true;
		}
	}
	else{
		if(cnt2==0){
			ok=true;
		}
	}
	cout<<(ok ? "Yes" : "No")<<'\n';
	return 0;
}
