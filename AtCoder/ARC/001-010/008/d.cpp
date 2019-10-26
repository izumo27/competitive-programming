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

const int MAX_N=1<<17;

struct SegmentTree{
	int n;
	vector<pair<double, double>> dat;

	SegmentTree(int n_=1){
		init(n_);
	}

	// n要素で初期化
	void init(int n_=1){
		n=1;
		while(n<n_){
			n<<=1;
		}
		dat.resize(n*2-1);
		REP(i, n*2-1){
			dat[i]=make_pair(1, 0);
		}
	}

	void update(ll k, double a, double b){
		k+=n-1;
		dat[k]=make_pair(a, b);
		while(k>0){
			k=(k-1)/2;
			double a1=dat[k*2+1].first, b1=dat[k*2+1].second, a2=dat[k*2+2].first, b2=dat[k*2+2].second;
			dat[k]=make_pair(a1*a2, b1*a2+b2);
		}
	}

	double query(){
		return dat[0].first+dat[0].second;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	ll n, p[114514];
	double a[114514], b[114514];
	cin>>n>>m;
	vl P;
	REP(i, m){
		cin>>p[i]>>a[i]>>b[i];
		P.push_back(p[i]);
	}
	sort(ALL(P));
	P.erase(unique(ALL(P)), P.end());
	REP(i, m){
		p[i]=lower_bound(ALL(P), p[i])-P.begin();
	}
	SegmentTree st(m);
	double mi=1, ma=1;
	REP(i, m){
		st.update(p[i], a[i], b[i]);
		double tmp=st.query();
		mi=min(mi, tmp);
		ma=max(ma, tmp);
	}
	cout<<fixed;
	cout<<setprecision(8);
	cout<<mi<<'\n';
	cout<<ma<<'\n';
	return 0;
}
