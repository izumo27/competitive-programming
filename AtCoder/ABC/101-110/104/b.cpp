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
	if(s[0]!='A'){
		cout<<"WA"<<'\n';
		return 0;
	}
	int ok=0;
	int tmp;
	FOR(i, 2, s.size()-1){
		if(s[i]=='C'){
			++ok;
			tmp=i;
		}
	}
	if(ok==1){
		FOR(i, 1, s.size()){
			if(i!=tmp && s[i]-'a'<0 || s[i]-'a'>26){
					cout<<"WA"<<'\n';
					return 0;
			}
		}
		cout<<"AC"<<'\n';
	}else{
		cout<<"WA"<<'\n';
	}
	return 0;
}
