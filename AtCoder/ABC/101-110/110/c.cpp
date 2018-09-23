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

char alf1[30];
char alf2[30];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin>>s>>t;
	REP(i, 30){
		alf1[i]='#';
		alf2[i]='#';
	}
	REP(i, s.size()){
		if(alf1[s[i]-'a']!='#'){
			if(t[i]!=alf1[s[i]-'a']){
				cout<<"No"<<'\n';
				return 0;
			}
		}
		else{
			alf1[s[i]-'a']=t[i];
		}
		if(alf2[t[i]-'a']!='#'){
			if(s[i]!=alf2[t[i]-'a']){
				cout<<"No"<<'\n';
				return 0;
			}
		}
		else{
			alf2[t[i]-'a']=s[i];
		}
	}
	cout<<"Yes"<<'\n';
	return 0;
}
