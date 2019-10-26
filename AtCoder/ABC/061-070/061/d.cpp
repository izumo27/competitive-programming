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

const ll INF=1e18;
const int MAX_E=2525;
const int MAX_V=1252;

struct edge {
	int from;
	int to;
 	ll cost;
};

// 辺
edge es[MAX_E];

// 最短距離
ll d[MAX_V];
int V, E;

bool shortest_path(int s){
	fill(d, d+V, INF);
	d[s]=0;
	REP(i, V){
		bool update=false;
		REP(j, E){
			edge e=es[j];
			if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				update=true;
				if(i==V-1 && e.to==V-1){
					return false;
				}
			}
		}
		if(!update){
			break;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b;
	ll c;
	cin>>n>>m;
	V=n;
	E=m;
	REP(i, m){
		edge e;
		cin>>a>>b>>c;
		e.from=a-1;
		e.to=b-1;
		e.cost=-c;
		es[i]=e;
	}
	if(shortest_path(0)){
		cout<<-d[n-1]<<'\n';
	}
	else{
		cout<<"inf"<<'\n';
	}
	return 0;
}
