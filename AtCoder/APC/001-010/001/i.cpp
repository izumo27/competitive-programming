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

int h, w, n, x[40], y[40], xnum[1364364], ynum[1364364], H, W;
vi X, Y;
ll ans;
bool used[70][70];
int d[70][70], dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

ll bfs(){
	ll res=0;
	REP(i, H){
		REP(j, W){
			if(used[i][j]){
				continue;
			}
			REP(k, H){
				REP(l, W){
					d[k][l]=-1;
				}
			}
			queue<pii> q;
			q.push(pii(i, j));
			d[i][j]=0;
			while(!q.empty()){
				pii p=q.front();
				q.pop();
				int sx=p.first, sy=p.second;
				REP(k, 4){
					int tx=sx+dx[k], ty=sy+dy[k];
					if(tx<0 || tx>=H || ty<0 || ty>=W || used[tx][ty] || d[tx][ty]!=-1){
						continue;
					}
					d[tx][ty]=d[sx][sy]+1;
					q.push(pii(tx, ty));
				}
			}
			REP(k, H){
				REP(l, W){
					if(used[k][l] || d[k][l]==-1){
						continue;
					}
					ll tmp1=((ll)X[i+1]-X[i])*(Y[j+1]-Y[j])%MOD, tmp2=((ll)X[k+1]-X[k])*(Y[l+1]-Y[l])%MOD;
					res=(res+d[k][l]*tmp1%MOD*tmp2%MOD)%MOD;
				}
			}
		}
	}
	return (res*500000004)%MOD;
}

void compress(){
	X.push_back(0);
	X.push_back(h);
	Y.push_back(0);
	Y.push_back(w);
	REP(i, n){
		X.push_back(x[i]);
		X.push_back(x[i]+1);
		Y.push_back(y[i]);
		Y.push_back(y[i]+1);
		++xnum[x[i]];
		++ynum[y[i]];
	}
	sort(ALL(X));
	sort(ALL(Y));
	X.erase(unique(ALL(X)), X.end());
	Y.erase(unique(ALL(Y)), Y.end());
	H=X.size()-1;
	W=Y.size()-1;
	REP(i, n){
		int itrx=find(ALL(X), x[i])-X.begin();
		int itry=find(ALL(Y), y[i])-Y.begin();
		used[itrx][itry]=true;
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>h>>w>>n;
	REP(i, n){
		cin>>x[i]>>y[i];
	}
	compress();
	ll sub=w-xnum[0], sum=(ll)h*w-n;
	REP(i, h-1){
		if(xnum[i]==0 && xnum[i+1]==0){
			ll tmp1=sub%MOD, tmp2=(sum-sub)%MOD;
			ans=(ans+tmp1*tmp2)%MOD;
		}
		sub+=w-xnum[i+1];
	}
	// DEBUG(ans);
	sub=h-ynum[0];
	REP(i, w-1){
		if(ynum[i]==0 && ynum[i+1]==0){
			ll tmp1=sub%MOD, tmp2=(sum-sub)%MOD;
			ans=(ans+tmp1*tmp2)%MOD;
		}
		sub+=h-ynum[i+1];
	}
	// DEBUG(ans);
	ans=(ans+bfs())%MOD;
	cout<<ans<<'\n';
	return 0;
}
