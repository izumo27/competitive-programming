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

int n, a, b, c[12525];
int ans[12525];
vi g[12525];

void bfs(int s){
	queue<int> q;
	q.push(s);
	int cnt=n-1;
	ans[s]=c[cnt];
	while(q.size()){
		int p=q.front();
		q.pop();
		for(auto& x : g[p]){
			if(ans[x]!=-1){
				continue;
			}
			ans[x]=c[--cnt];
			// DEBUG(cnt);
			q.push(x);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	cin>>n;
	REP(i, n-1){
		cin>>a>>b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int sum=0;
	REP(i, n){
		cin>>c[i];
		sum+=c[i];
	}
	sort(c, c+n);
	int ma=c[n-1];
	REP(i, n){
		ans[i]=-1;
	}
	bfs(0);
	cout<<sum-ma<<'\n';
	REP(i, n){
		cout<<ans[i]<<" \n"[i==n-1];
	}
	return 0;
}
