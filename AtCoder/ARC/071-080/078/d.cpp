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

vi g[114514];
int d[114514], d2[114514];

void dfs(int x, int a){
	if(d[x]!=-1){
		return;
	}
	d[x]=a;
	for(int y : g[x]){
		dfs(y, a+1);
	}
}

void dfs2(int x, int a){
	if(d2[x]!=-1){
		return;
	}
	d2[x]=a;
	for(int y : g[x]){
		dfs2(y, a+1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	cin>>n;
	REP(i, n-1){
		cin>>a>>b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	REP(i, n){
		d[i]=-1;
		d2[i]=-1;
	}
	dfs(0, 0);
	dfs2(n-1, 0);
	int cnt=0;
	REP(i, n){
		if(d[i]<=d2[i]){
			++cnt;
		}
	}
	cout<<(cnt*2>n ? "Fennec" : "Snuke")<<'\n';
	return 0;
}
