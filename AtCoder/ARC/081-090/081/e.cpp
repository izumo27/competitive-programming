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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int len[252521];
vi alp[30];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	string a;
	cin>>a;
	int n=a.size();
	map<int, int> mp;
	int cnt=0;
	FORR(i, 0, n){
		++mp[a[i]-'a'];
		len[i+1]=cnt;
		alp[a[i]-'a'].push_back(i);
		if(mp.size()==26){
			mp.clear();
			++cnt;
		}
	}
	len[0]=cnt;
	len[n+1]=-1;
	REP(i, 26){
		reverse(ALL(alp[i]));
		alp[i].push_back(n);
	}
	string ans="";
	int sz=-1, now=-1;
	while(sz<cnt){
		++sz;
		REP(i, 26){
			// DEBUG(len[now+1]);
			// DEBUG(len[*lower_bound(ALL(alp[i]), now+1)+1]);
			if(len[now+1]!=len[*lower_bound(ALL(alp[i]), now+1)+1]){
				ans+='a'+i;
				now=*lower_bound(ALL(alp[i]), now+1);
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
