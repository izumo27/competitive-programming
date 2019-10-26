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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

template<typename T> struct SegmentTree_sum{
	int n;
	vector<T> node;
	T ZERO;

	SegmentTree_sum(const int &n_=1, const T &ZERO_=0){
		init(n_, ZERO_);
	}

	// n要素で初期化
	void init(const int &n_=1, const T &ZERO_=0){
		n=1;
		while(n<n_){
			n<<=1;
		}
		node.resize(n*2-1);
		ZERO=ZERO_;
		REP(i, n*2-1){
			node[i]=ZERO;
		}
	}

	// k番目(0-indexed)をaに変更
	void update(int k, const T &a){
		k+=n-1;
		node[k]=a;
		while(k>0){
			k=(k-1)/2;
			node[k]=node[k*2+1]+node[k*2+2];
		}
	}

	// [a, b)の和を求める
	// k: 節点の番号、その節点は[l, r)に対応づく
	// 外から呼び出すときはquery(a, b, 0, 0, n)
	T query(int a, int b, int k, int l, int r){
		// [a, b)と[l, r)が交差しなければZERO
		if(r<=a || b<=l){
			return ZERO;
		}
		// [a, b)と[l, r)が完全に含んでいればこの節点の値
		if(a<=l && r<=b){
			return node[k];
		}
		// そうでなければ2つの子の和
		else{
			T v1=query(a, b, k*2+1, l, (l+r)/2), v2=query(a, b, k*2+2, (l+r)/2, r);
			return v1+v2;
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, k;
	ll a[252521];
	pair<ll, int> b[252521];
	cin>>n>>k;
	b[0]=make_pair(0, 0);
	REP(i, n){
		cin>>a[i];
		b[i+1]=make_pair(b[i].first+a[i]-k, i+1);
	}
	sort(b, b+n+1);
	ll c[252521];
	REP(i, n+1){
		c[b[i].second]=i;
	}
	SegmentTree_sum<int> st(n+1);
	ll ans=0;
	st.update(c[0], 1);
	FOR(i, 1, n+1){
		ans+=st.query(0, c[i], 0, 0, st.n);
		int tmp=st.query(c[i], c[i]+1, 0, 0, st.n);
		st.update(c[i], tmp+1);
	}
	cout<<ans<<'\n';
	return 0;
}
