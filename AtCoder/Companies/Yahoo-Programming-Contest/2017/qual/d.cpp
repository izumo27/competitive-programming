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
	vector<pll> dat;

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
			dat[i]=pll(0, 0);
		}
	}

	pll add(pll a, pll b){
		return pll(a.first+b.first, max(a.second+b.first, b.second));
	}

	void update(int k, pll a){
		k+=n-1;
		dat[k]=a;
		while(k>0){
			k=(k-1)/2;
			dat[k]=add(dat[k*2+1], dat[k*2+2]);
		}
	}

	pll query(int a, int b, int k, int l, int r){
		if(r<=a || b<=l){
			return pll(0, 0);
		}
		if(a<=l && r<=b){
			return dat[k];
		}
		pll v1=query(a, b, k*2+1, l, (l+r)/2), v2=query(a, b, k*2+2, (l+r)/2, r);
		return add(v1, v2);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, info[114514], d[114514];
	ll k, a[114514];
	cin>>q>>k;
	vi D;
	REP(i, q){
		cin>>info[i]>>d[i];
		if(info[i]==1){
			cin>>a[i];
		}
		D.push_back(d[i]);
	}
	sort(ALL(D));
	D.erase(unique(ALL(D)), D.end());
	int size=D.size();
	SegmentTree st(size);
	st.update(0, pll(D[0]*k, 0));
	FOR(i, 1, size){
		st.update(i, pll((D[i]-D[i-1])*k, 0));
	}
	REP(i, q){
		int dd=lower_bound(ALL(D), d[i])-D.begin();
		if(info[i]==1){
			pll x=st.dat[dd+st.n-1];
			st.update(dd, pll(x.first-a[i], x.second));
		}else{
			pll x=st.query(0, dd+1, 0, 0, st.n);
			cout<<d[i]*k-max(x.first, x.second)<<'\n';
			// DEBUG(x.first);
		}
	}
	return 0;
}
