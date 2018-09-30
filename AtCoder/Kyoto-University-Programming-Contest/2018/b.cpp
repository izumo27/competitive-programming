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

int h, w;
string c[12];
bool can[12][12];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>h>>w;
	REP(i, h){
		cin>>c[i];
	}
	int x;
	REP(i, w){
		if(c[h-1][i]=='s'){
			x=i;
			break;
		}
	}
	can[h-1][x]=true;
	FORR(i, 0, h-1){
		REP(j, w){
			if(c[i][j]=='x'){
				continue;
			}
			bool ok=false;
			FOR(k, max(0, j-1), min(j+2, w)){
				if(can[i+1][k]){
					ok=true;
				}
			}
			if(ok){
				can[i][j]=true;
			}
		}
	}
	int y=-1;
	REP(i, w){
		if(can[0][i]){
			y=i;
		}
	}
	if(y==-1){
		cout<<"impossible"<<'\n';
		return 0;
	}
	string ans="";
	REP(i, h-1){
		REP(j, w){
			if(can[i+1][j] && y-1<=j && j<=y+1){
				if(y-1==j){
					ans+='R';
				}
				else if(y==j){
					ans+='S';
				}
				else{
					ans+='L';
				}
				y=j;
				break;
			}
		}
	}
	FORR(i, 0, h-1){
		cout<<ans[i];
	}
	cout<<'\n';
	return 0;
}
