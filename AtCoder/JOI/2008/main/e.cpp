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

int W, H, n, X1[1333], Y1[1333], X2[1333], Y2[1333], dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
bool fld[3114][3114];

int compress(int *x1, int *x2, int w){
	vi xs;
	REP(i, n){
		xs.push_back(x1[i]);
		xs.push_back(x2[i]);
	}
	xs.push_back(0);
	xs.push_back(w);
	sort(ALL(xs));
	xs.erase(unique(ALL(xs)), xs.end());
	REP(i, n){
		x1[i]=find(ALL(xs), x1[i])-xs.begin();
		x2[i]=find(ALL(xs), x2[i])-xs.begin();
	}
	return xs.size();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>W>>H>>n;
	REP(i, n){
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
	}
	W=compress(X1, X2, W);
	H=compress(Y1, Y2, H);
	REP(i, n){
		FOR(j, X1[i], X2[i]){
			FOR(k, Y1[i], Y2[i]){
				fld[j][k]=true;
			}
		}
	}
	--W;
	--H;
	int ans=0;
	REP(x, W){
		REP(y, H){
			if(fld[x][y]){
				continue;
			}
			// DEBUG(x);
			// DEBUG(y);
			++ans;
			fld[x][y]=true;
			queue<pii> que;
			que.push(pii(x, y));
			while(!que.empty()){
				int sx=que.front().first, sy=que.front().second;
				que.pop();
				REP(i, 4){
					int tx=sx+dx[i], ty=sy+dy[i];
					if(tx<0 || W<=tx || ty<0 || H<=ty){
						continue;
					}
					if(fld[tx][ty]){
						continue;
					}
					que.push(pii(tx, ty));
					fld[tx][ty]=true;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
