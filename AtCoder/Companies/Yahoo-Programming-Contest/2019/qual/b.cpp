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

bool used[5];
bool g[5][5];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a[5], b[5];
	REP(i, 3){
		cin>>a[i]>>b[i];
		--a[i];
		--b[i];
		g[a[i]][b[i]]=g[b[i]][a[i]]=true;
	}

	REP(i, 4){
		REP(j, 4){
			used[j]=false;
		}
		used[i]=true;
		int now=i;
		REP(i, 3){
			REP(j, 4){
				if(g[now][j] && !used[j]){
					now=j;
					used[now]=true;
					break;
				}
			}
		}
		bool ok=true;
		REP(i, 4){
			if(!used[i]){
				ok=false;
				break;
			}
		}
		if(ok){
			cout<<"YES"<<'\n';
			return 0;
		}
	}
	cout<<"NO"<<'\n';
	return 0;
}
