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
	string s;
	cin>>s;
	int n=s.size();
	bool ok=true;
	if(s[0]!='1' || s[n-1]!='0'){
		ok=false;
	}
	REP(i, (n-1)/2){
		if(s[i]!=s[n-2-i]){
			ok=false;
			break;
		}
	}
	if(!ok){
		cout<<-1<<'\n';
		return 0;
	}
	int num=0;
	FOR(i, 1, n){
		if(s[i]=='1'){
			FOR(j, num+1, i+1){
				cout<<num+1<<' '<<j+1<<'\n';
			}
			cout<<num+1<<' '<<i+2<<'\n';
			num=i+1;
		}
	}
	return 0;
}
