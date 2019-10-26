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
	vl dat;

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
			dat[i]=0;
		}
	}

	void update(int k, ll a){
		k+=n-1;
		dat[k]=a;
		while(k>0){
			k=(k-1)/2;
			dat[k]=max(dat[k*2+1], dat[k*2+2]);
		}
	}

	// [a, b)の最大値を求める
	// k: 節点の番号、その節点は[l, r)に対応づく
	// 外から呼び出すときはquery(a, b, 0, 0, n)
	ll query(int a, int b, int k, int l, int r){
		if(r<=a || b<=l){
			return 0;
		}
		if(a<=l && r<=b){
			return dat[k];
		}
		else{
			ll v1=query(a, b, k*2+1, l, (l+r)/2), v2=query(a, b, k*2+2, (l+r)/2, r);
			return max(v1, v2);
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, num;
	ll a[114514];
	cin>>n;
	ll sum=0;
	REP(i, n){
		cin>>a[i];
		sum+=a[i];
	}
	SegmentTree st(n);
	REP(i, n){
		cin>>num;
		--num;
		st.update(num, st.query(0, num, 0, 0, st.n)+a[num]);
	}
	cout<<(sum-st.query(0, n, 0, 0, st.n))*2<<'\n';
	return 0;
}
