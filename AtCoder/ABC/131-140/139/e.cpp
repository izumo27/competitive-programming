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

#define DEBUG(x) cout<<#x<<": "<<(x)<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

constexpr int INF=1e9;
int b[1252][1252];
int idx[1252];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, a[1252][1252];
	cin>>n;
	REP(i, n)REP(j, n-1){
		cin>>a[i][j];
		--a[i][j];
	}
	REP(i, n)FOR(j, 1, n){
		b[i][j]=INF;
	}
	queue<pii> q;
	REP(i, n-1){
		int t=a[i][0];
		if(i==a[t][0] && i<t){
			q.push(pii(i, t));
			++idx[i];
			++idx[t];
		}
	}
	while(q.size()){
		auto x=q.front();
		q.pop();
		int y=x.first;
		// DEBUG(y);
		if(idx[y]<n-1 && b[y][idx[y]]==INF){
			int t=a[y][idx[y]];
			if(y==a[t][idx[t]]){
				// DEBUG(t);
				q.push(pii(y, t));
				b[y][idx[y]]=b[t][idx[t]]=max(b[y][idx[y]-1], b[t][idx[t]-1])+1;
				// DEBUG(b[y][idx[y]]);
				++idx[y];
				++idx[t];
			}
		}
		y=x.second;
		// DEBUG(y);
		if(idx[y]<n-1 && b[y][idx[y]]==INF){
			int t=a[y][idx[y]];
			if(y==a[t][idx[t]]){
				// DEBUG(t);
				q.push(pii(y, t));
				b[y][idx[y]]=b[t][idx[t]]=max(b[y][idx[y]-1], b[t][idx[t]-1])+1;
				// DEBUG(b[y][idx[y]]);
				++idx[y];
				++idx[t];
			}
		}
	}
	int ans=0;
	REP(i, n){
		CHMAX(ans, b[i][n-2]);
	}
	cout<<(ans!=INF ? ans+1 : -1)<<'\n';
	return 0;
}
