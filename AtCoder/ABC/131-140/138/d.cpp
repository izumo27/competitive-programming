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

vi g[252525];
ll num[252525];
ll ans[252525];
bool used[252525];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, Q, a, b, p[252525], x[252525];
	cin>>n>>Q;
	REP(i, n-1){
		cin>>a>>b;
		--a;--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	REP(i, Q){
		cin>>p[i]>>x[i];
		--p[i];
		num[p[i]]+=x[i];
	}
	queue<pll> q;
	q.push(pll(0ll, 0ll));
	used[0]=true;
	while(q.size()){
		pll y=q.front();
		q.pop();
		ans[y.first]=y.second+num[y.first];
		for(auto &z : g[y.first]){
			if(used[z]){
				continue;
			}
			used[z]=true;
			q.push(pll(z, ans[y.first]));
		}
	}
	REP(i, n){
		cout<<ans[i]<<" \n"[i==n-1];
	}
	return 0;
}
