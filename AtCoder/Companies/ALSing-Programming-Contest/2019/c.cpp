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

bool used[404][404];
int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
int h, w;
string s[404];

pll bfs(int sx, int sy){
	queue<pair<pii, bool>> q;
	q.push(make_pair(pii(sx, sy), true));
	ll cnt1=0, cnt2=0;
	while(q.size()){
		pair<pii, bool> p=q.front();
		q.pop();
		REP(i, 4){
			int nx=p.first.first+dx[i];
			int ny=p.first.second+dy[i];
			if(nx>=0 && nx<h && ny>=0 && ny<w && !used[nx][ny]){
				if(p.second){
					if(s[nx][ny]=='.'){
						++cnt2;
						q.push(make_pair(pii(nx, ny), false));
						used[nx][ny]=true;
					}
				}
				else{
					if(s[nx][ny]=='#'){
						++cnt1;
						q.push(make_pair(pii(nx, ny), true));
						used[nx][ny]=true;
					}
				}
			}
		}
	}
	return pll(cnt1, cnt2);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>h>>w;
	REP(i, h){
		cin>>s[i];
	}
	ll ans=0;
	REP(i, h){
		REP(j, w){
			if(s[i][j]!='#'){
				continue;
			}
			pll cnt=bfs(i, j);
			ans+=cnt.first*cnt.second;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
