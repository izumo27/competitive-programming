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

int n, m;
char s[2525][2525];
bool reached[4][2525][2525];
int num[4][2525][2525];
int dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};

void dfs(int x, int y, int d){
	if(x<0 || x>=n || y<0 || y>=m || s[x][y]=='#') return;
	if(reached[d][x][y]) return;
	reached[d][x][y]=true;
	if(x-dx[d]>=0 && x-dx[d]<n && y-dy[d]>=0 && y-dy[d]<m && s[x-dx[d]][y-dy[d]]!='#'){
		num[d][x][y]=num[d][x-dx[d]][y-dy[d]]+1;
	}
	dfs(x+dx[d], y+dy[d], d);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	REP(i, n){
		REP(j, m){
			cin>>s[i][j];
		}
	}
	// 右
	REP(i, n){
		REP(j, m){
			dfs(i, j, 0);
		}
	}
	// 左
	REP(i, n){
		FORR(j, 0, m){
			dfs(i, j, 1);
		}
	}
	// 下
	REP(i, m){
		REP(j, n){
			dfs(j, i, 2);
		}
	}
	// 上
	REP(i, m){
		FORR(j, 0, n){
			dfs(j, i, 3);
		}
	}
	// REP(j, n){
	// 	REP(k, m){
	// 		DEBUG(j);
	// 		DEBUG(k);
	// 		DEBUG(num[2][j][k]);
	// 	}
	// }
	ll ans=0;
	REP(i, n){
		REP(j, m){
			ans+=(num[0][i][j]+num[1][i][j])*(num[2][i][j]+num[3][i][j]);
			// DEBUG(num[2][i][j]);
			// DEBUG(num[3][i][j]);
			// DEBUG(ans);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
