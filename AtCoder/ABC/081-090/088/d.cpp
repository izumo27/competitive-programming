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
int h, w, d[60][60], dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
char s[60][60];

void bfs(){
	queue<pii> q;
	REP(i, h){
		REP(j, w) d[i][j]=INF;
	}
	q.push(pii(0, 0));
	d[0][0]=0;
	while(q.size()){
		pii p=q.front();
		q.pop();
		if(p.first==h-1 && p.second==w-1) return;
		REP(i, 4){
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			if(nx>=0 && nx<h && ny>=0 && ny<w && s[nx][ny]!='#' && d[nx][ny]==INF){
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
	cin>>h>>w;
	int count=0;
	REP(i, h){
		REP(j, w){
			cin>>s[i][j];
			if(s[i][j]=='.') ++count;
		}
	}
	bfs();
	d[h-1][w-1]!=INF ? cout<<count-d[h-1][w-1]-1<<'\n' : cout<<-1<<'\n';
	return 0;
}
