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

vi g[114514], g2[114514];
int root, child;
bool used[114514], used2[114514];
pii ans[114514];

void dfs(int u){
	if(g[u].size()>1){
		for(auto v : g[u]){
			bool ok=true;
			for(auto v2 : g2[v]){
				if(ans[v2].first==0){
					ok=false;
					break;
				}
			}
			if(ok && ans[v].second<ans[u].second+1){
				ans[v]=pii(u, ans[u].second+1);
				dfs(v);
			}
		}
	}
	else{
		if(g[u].size()==0){
			return;
		}
		ans[g[u][0]]=pii(u, ans[u].second+1);
		dfs(g[u][0]);
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b;
	cin>>n>>m;
	REP(i, n+m){
		cin>>a>>b;
		g[a].push_back(b);
		g2[b].push_back(a);
		used[b]=true;
		used2[a]=true;
	}
	FOR(i, 1, n+1){
		if(!used[i]){
			root=i;
			break;
		}
	}
	FOR(i, 1, n+1){
		if(!used2[i]){
			child=i;
			break;
		}
	}
	ans[root]=pii(-1, 0);
	dfs(root);
	FOR(i, 1, n+1){
		if(ans[i].first!=-1){
			cout<<ans[i].first<<'\n';
		}
		else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
