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

int used[114514], ans[114514];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, p[114514], y[114514];
	pair<int, pii> yp[114514];
	cin>>n>>m;
	REP(i, m){
		cin>>p[i]>>y[i];
		yp[i]=make_pair(y[i], pii(p[i], i));
	}
	sort(yp, yp+m);
	REP(i, m){
		ans[yp[i].second.second]=++used[yp[i].second.first];
	}
	REP(i, m){
		int tmp=p[i], cnt=0;
		while(tmp>0){
			tmp/=10;
			++cnt;
		}
		REP(j, 6-cnt){
			cout<<0;
		}
		cout<<p[i];
		tmp=ans[i];
		cnt=0;
		while(tmp>0){
			tmp/=10;
			++cnt;
		}
		REP(j, 6-cnt){
			cout<<0;
		}
		cout<<ans[i]<<'\n';
	}
	return 0;
}
