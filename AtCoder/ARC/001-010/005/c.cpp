#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORR(i, a, b) for(int i=b-1; i>=a; --i)

const int INF=1<<20;
int h, w, sx, sy, gx, gy, d[514][514], dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
char c[514][514];
bool ok;

void bfs(){
	queue<pii> q;
	REP(i, h){
		REP(j, w) d[i][j]=INF;
	}
	q.push(pii(sx, sy));
	d[sx][sy]=0;
	while(q.size()){
		pii p=q.front();
		q.pop();
		if(p.first==gx && p.second==gy && d[gx][gy]<=2){
			ok=true;
			return;
		}
		REP(i, 4){
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			if(nx>=0 && nx<h && ny>=0 && ny<w){
				if(c[nx][ny]=='#' && d[p.first][p.second]+1<d[nx][ny] && d[p.first][p.second]<2){
					q.push(pii(nx, ny));
					d[nx][ny]=d[p.first][p.second]+1;
				}
				else if(c[nx][ny]=='.' && d[p.first][p.second]<d[nx][ny]){
					q.push(pii(nx, ny));
					d[nx][ny]=d[p.first][p.second];
				}
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>h>>w;
	REP(i, h){
		REP(j, w){
			cin>>c[i][j];
			if(c[i][j]=='s'){
				sx=i;
				sy=j;
				c[i][j]='.';
			}
			if(c[i][j]=='g'){
				gx=i;
				gy=j;
				c[i][j]='.';
			}
		}
	}
	bfs();
	ok ? cout<<"YES"<<'\n' : cout<<"NO"<<'\n';
	return 0;
}
