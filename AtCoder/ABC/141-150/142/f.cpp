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

int n, m, a, b;
vi g[1252];
int h[1252][1252];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	cin>>n>>m;
	REP(i, m){
		cin>>a>>b;
		--a;--b;
		g[a].push_back(b);
		h[a][b]=1;
	}
	REP(i, n){
		vi v;
		queue<pair<int, vi>> q;
		q.push(make_pair(i, v));
		while(q.size()){
			auto t=q.front();
			q.pop();
			int s=t.first;
			vi u=t.second;
			u.push_back(s);
			FORR(j, 0, u.size()){
				for(auto t : g[s]){
					if(t==u[j]){
						cout<<u.size()-j<<'\n';
						REP(k, u.size()-j){
							cout<<u[j+k]+1<<'\n';
						}
						return 0;
					}
				}
			}
			for(auto t : g[s]){
				q.push(make_pair(t, u));
			}
		}
	}
	cout<<-1<<'\n';
	return 0;
}
