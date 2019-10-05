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

#define DEBUG(x) cout<<#x<<": "<<(x)<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n;
	string s[252];
	int t[252][252];
	cin>>n;
	REP(i, n){
		cin>>s[i];
		REP(j, n){
			t[i][j]=s[i][j]-'0';
		}
	}
	int ans=0;
	REP(x, n){
		queue<pii> q;
		q.push(pii(x, 1));
		int deg[252];
		int tmp=0;
		REP(i, n){
			deg[i]=-1;
		}
		while(q.size()){
			pii a=q.front();
			q.pop();
			if(deg[a.first]>0){
				continue;
			}
			deg[a.first]=tmp=a.second;
			REP(i, n){
				if(t[a.first][i]){
					if(deg[i]>0 && (deg[a.first]==deg[i] || abs(deg[a.first]-deg[i])>1)){
						cout<<-1<<'\n';
						return 0;
					}
					q.push(pii(i, a.second+1));
				}
			}
		}
		CHMAX(ans, tmp);
	}
	cout<<ans<<'\n';
	return 0;
}
