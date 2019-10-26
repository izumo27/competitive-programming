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

int T, N, M, a[31333], b[31333], s[31333][10], skill_level[10];
ll c[31333], money;

ll score(int t, int i){
	double add_money=(double)c[i];
	add_money*=(1+9*(double)(t-a[i])/(b[i]-a[i]));
	int skill_lack=0;
	REP(j, N){
		skill_lack+=max(0, s[i][j]-skill_level[j]);
	}
	if(skill_lack){
		add_money*=pow(0.5, skill_lack);
	}
	else{
		add_money*=10;
	}
	return (ll)add_money;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T>>N>>M;
	REP(i, M){
		cin>>a[i]>>b[i]>>c[i];
		--a[i];
		--b[i];
		REP(j, N){
			cin>>s[i][j];
		}
	}
	REP(i, T){
		ll reward=0;
		int ind=0;
		REP(j, M){
			if(i!=b[j]){
				continue;
			}
			ll tmp=score(i, j);
			if(reward<tmp){
				reward=tmp;
				ind=j;
			}
		}
		if(reward>1000){
			cout<<2<<' '<<ind+1<<'\n';
			money+=reward;
		}
		else{
			cout<<3<<'\n';
			money+=1000;
		}
	}
	return 0;
}
