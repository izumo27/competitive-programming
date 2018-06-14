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

const int INF=1<<30;

int r, c, sy, sx, gy, gx, d[60][60], dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
char maze[60][60];

void bfs(){
	queue<pii> q;
	REP(i, r){
		REP(j, c) d[i][j]=INF;
	}
	q.push(pii(sx, sy));
	d[sx][sy]=0;
	while(q.size()){
		pii p=q.front();
		q.pop();
		if(p.first==gx && p.second==gy) return;
		REP(i, 4){
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			if(nx>=0 && nx<r && ny>=0 && ny<c && maze[nx][ny]!='#' && d[nx][ny]==INF){
				q.push(pii(nx, ny));
				d[nx][ny]=d[p.first][p.second]+1;
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>r>>c>>sx>>sy>>gx>>gy;
	--sy;
	--sx;
	--gy;
	--gx;
	REP(i, r){
		REP(j, c) cin>>maze[i][j];
	}
	bfs();
	cout<<d[gx][gy]<<'\n';
	return 0;
}
