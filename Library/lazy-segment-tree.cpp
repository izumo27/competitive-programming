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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const int MAX_N=1<<17;

template<typename T> struct LazySegmentTree_max{
	int n;
	vector<T> node, lazy;
	T MIN;

	LazySegmentTree_max(const vector<T> &v, const T &MIN_=0){
		init(v, MIN_);
	}

	// nodeの初期化
	void init(const vector<T> &v, const T &MIN_){
		int n_=v.size();
		n=1;
		while(n<n_){
			n<<=1;
		}
		node.resize(n*2-1);
		lazy.resize(n*2-1, 0);
		MIN=MIN_
		REP(i, n_){
			node[i+n-1]=v[i];
		}
		FORR(i, 0, n-1){
			node[i]=node[i*2+1]+node[i*2+2];
		}
	}

	// k番目(0-indexed)を遅延評価
	void eval(int k, int l, int r){
		// 遅延配列が空なら子へ伝搬しない
		if(lazy[k]==0){
			return;
		}
		node[k]+=lazy[k];
		// 最下段でなければ伝搬
		if(r-l>1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
	}

	// k番目(0-indexed)をaに変更
	void update(int k, const T &a){
		k+=n-1;
		node[k]=a;
		while(k>0){
			k=(k-1)/2;
			node[k]=max(node[k*2+1], node[k*2+2]);
		}
	}

	// [a, b)にxを加える
	// k: 節点の番号、その節点は[l, r)に対応づく
	void add(int a, int b, const T &x, int k, int l, int r){
		eval(k, l, r);
		// [a, b)と[l, r)が交差しなければ何もしない
		if(r<=a || b<=l){
			return;
		}
		// [a, b)と[l, r)が完全に含んでいれば遅延配列に値を入れて評価
		if(a<=l && r<=b){
			lazy[k]+=x;
			eval(k, l, r);
		}
		// そうでなければ子を再帰的に計算し更新
		else{
			add(a, b, x, k*2+1, l, (l+r)/2);
			add(a, b, x, k*2+2, (l+r)/2, r);
			node[k]=max(node[k*2+1], node[k*2+2]);
		}
	}

	// [a, b)の最大値を求める
	// k: 節点の番号、その節点は[l, r)に対応づく
	T query(int a, int b, int k, int l, int r){
		// [a, b)と[l, r)が交差しなければMIN
		if(r<=a || b<=l){
			return MIN;
		}
		eval(k, l, r);
		// [a, b)と[l, r)が完全に含んでいればこの節点の値
		if(a<=l && r<=b){
			return node[k];
		}
		// そうでなければ2つの子の最大値
		else{
			T v1=query(a, b, k*2+1, l, (l+r)/2), v2=query(a, b, k*2+2, (l+r)/2, r);
			return max(v1, v2);
		}
	}

	void add(int a, int b, const T &x){
		add(a, b, x, 0, 0, n);
	}

	T query(int a, int b){
		return query(a, b, 0, 0, n);
	}
};

template<typename T> struct LazySegmentTree_min{
	int n;
	vector<T> node, lazy;
	T MAX;

	LazySegmentTree_min(const vector<T> &v, const T &MAX_=INT_MAX){
		init(v, MAX_);
	}

	// nodeの初期化
	void init(const vector<T> &v, const T &MAX_){
		int n_=v.size();
		n=1;
		while(n<n_){
			n<<=1;
		}
		node.resize(n*2-1);
		lazy.resize(n*2-1, 0);
		MAX=MAX_
		REP(i, n_){
			node[i+n-1]=v[i];
		}
		FORR(i, 0, n-1){
			node[i]=node[i*2+1]+node[i*2+2];
		}
	}

	// k番目(0-indexed)を遅延評価
	void eval(int k, int l, int r){
		// 遅延配列が空なら子へ伝搬しない
		if(lazy[k]==0){
			return;
		}
		node[k]+=lazy[k];
		// 最下段でなければ伝搬
		if(r-l>1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
	}

	// k番目(0-indexed)をaに変更
	void update(int k, const T &a){
		k+=n-1;
		node[k]=a;
		while(k>0){
			k=(k-1)/2;
			node[k]=min(node[k*2+1], node[k*2+2]);
		}
	}

	// [a, b)にxを加える
	// k: 節点の番号、その節点は[l, r)に対応づく
	void add(int a, int b, const T &x, int k, int l, int r){
		eval(k, l, r);
		// [a, b)と[l, r)が交差しなければ何もしない
		if(r<=a || b<=l){
			return;
		}
		// [a, b)と[l, r)が完全に含んでいれば遅延配列に値を入れて評価
		if(a<=l && r<=b){
			lazy[k]+=x;
			eval(k, l, r);
		}
		// そうでなければ子を再帰的に計算し更新
		else{
			add(a, b, x, k*2+1, l, (l+r)/2);
			add(a, b, x, k*2+2, (l+r)/2, r);
			node[k]=min(node[k*2+1], node[k*2+2]);
		}
	}

	// [a, b)の最小値を求める
	// k: 節点の番号、その節点は[l, r)に対応づく
	T query(int a, int b, int k, int l, int r){
		// [a, b)と[l, r)が交差しなければMAX
		if(r<=a || b<=l){
			return MAX;
		}
		eval(k, l, r);
		// [a, b)と[l, r)が完全に含んでいればこの節点の値
		if(a<=l && r<=b){
			return node[k];
		}
		// そうでなければ2つの子の最小値
		else{
			T v1=query(a, b, k*2+1, l, (l+r)/2), v2=query(a, b, k*2+2, (l+r)/2, r);
			return min(v1, v2);
		}
	}

	void add(int a, int b, const T &x){
		add(a, b, x, 0, 0, n);
	}

	T query(int a, int b){
		return query(a, b, 0, 0, n);
	}
};

template<typename T> struct LazySegmentTree_sum{
	int n;
	vector<T> node, lazy;
	T ZERO;

	LazySegmentTree_sum(const vector<T> &v, const T &ZERO_=0){
		init(v, ZERO_);
	}

	// nodeの初期化
	void init(const vector<T> &v, const T &ZERO_=0){
		int n_=v.size();
		n=1;
		while(n<n_){
			n<<=1;
		}
		node.resize(n*2-1);
		lazy.resize(n*2-1, 0);
		ZERO=ZERO_;
		REP(i, n_){
			node[i+n-1]=v[i];
		}
		FORR(i, 0, n-1){
			node[i]=node[i*2+1]+node[i*2+2];
		}
	}

	// k番目(0-indexed)を遅延評価
	void eval(int k, int l, int r){
		// 遅延配列が空なら子へ伝搬しない
		if(lazy[k]==0){
			return;
		}
		node[k]+=lazy[k];
		// 最下段でなければ伝搬
		if(r-l>1){
			lazy[k*2+1]+=lazy[k]/2;
			lazy[k*2+2]+=lazy[k]/2;
		}
		lazy[k]=0;
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

	// [a, b)にxを加える
	// k: 節点の番号、その節点は[l, r)に対応づく
	void add(int a, int b, const T &x, int k, int l, int r){
		eval(k, l, r);
		// [a, b)と[l, r)が交差しなければ何もしない
		if(r<=a || b<=l){
			return;
		}
		// [a, b)と[l, r)が完全に含んでいれば遅延配列に値を入れて評価
		if(a<=l && r<=b){
			lazy[k]+=(r-l)*x;
			eval(k, l, r);
		}
		// そうでなければ子を再帰的に計算し更新
		else{
			add(a, b, x, k*2+1, l, (l+r)/2);
			add(a, b, x, k*2+2, (l+r)/2, r);
			node[k]=node[k*2+1]+node[k*2+2];
		}
	}

	// [a, b)の和を求める
	// k: 節点の番号、その節点は[l, r)に対応づく
	T query(int a, int b, int k, int l, int r){
		// [a, b)と[l, r)が交差しなければZERO
		if(r<=a || b<=l){
			return ZERO;
		}
		eval(k, l, r);
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

	void add(int a, int b, const T &x){
		add(a, b, x, 0, 0, n);
	}

	T query(int a, int b){
		return query(a, b, 0, 0, n);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
