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

vi g[114514];
bool used[114514];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, m, a, b;
	cin>>n>>m;
	REP(i, m){
		cin>>a>>b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	deque<int> ans;
	ans.push_front(0);
	ans.push_back(g[0][0]);
	if(g[0].size()==1 && g[g[0][0]].size()==1){
		cout<<2<<'\n';
		REP(i, 2){
			cout<<ans[i]+1<<" \n"[i==1];
		}
		return 0;
	}
	used[0]=used[g[0][0]]=true;
	bool can1=false, can2=false;
	FOR(i, 2, n){
		bool ok1=true;
		if(!can1){
			for(int x : g[ans.front()]){
				if(used[x]){
					continue;
				}
				ok1=false;
				ans.push_front(x);
				used[x]=true;
				break;
			}
			if(ok1){
				can1=true;
			}
		}
		bool ok2=true;
		if(!can2){
			for(int x : g[ans.back()]){
				if(used[x]){
					continue;
				}
				ok2=false;
				ans.push_back(x);
				used[x]=true;
				break;
			}
			if(ok2){
				can2=true;
			}
		}
		if(ok1 && ok2){
			break;
		}
	}
	int sz=ans.size();
	cout<<sz<<'\n';
	REP(i, sz){
		cout<<ans[i]+1<<" \n"[i==sz-1];
	}
	return 0;
}
