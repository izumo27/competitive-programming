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

template<typename T> struct LazySegmentTree_max{
	int n;
	vector<T> lazy, X, Y, XY, YX, XYX;
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
		lazy.resize(n*2-1, 0);
		MIN=MIN_;
		X.resize(n*2-1, MIN);
		Y.resize(n*2-1, MIN);
		XY.resize(n*2-1, MIN);
		YX.resize(n*2-1, MIN);
		XYX.resize(n*2-1, MIN);
		REP(i, n_){
			X[i+n-1]=v[i];
			Y[i+n-1]=-2*v[i];
		}
		FORR(i, 0, n-1){
			int l=i*2+1, r=i*2+2;
			X[i]=max(X[l], X[r]);
			Y[i]=max(Y[l], Y[r]);
			XY[i]=max({XY[l], XY[r], X[l]+Y[r]});
			YX[i]=max({YX[l], YX[r], Y[l]+X[r]});
			XYX[i]=max({XYX[l], XYX[r], X[l]+YX[r], XY[l]+X[r]});
		}
	}

	// k番目(0-indexed)を遅延評価
	void eval(int k, int l, int r){
		// 遅延配列が空なら子へ伝搬しない
		if(lazy[k]==0){
			return;
		}
		X[k]+=lazy[k];
		Y[k]+=-2*lazy[k];
		XY[k]+=-lazy[k];
		YX[k]+=-lazy[k];
		// 最下段でなければ伝搬
		if(r-l>1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
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
			int c=k*2+1, d=k*2+2;
			X[k]=max(X[c], X[d]);
			Y[k]=max(Y[c], Y[d]);
			XY[k]=max({XY[c], XY[d], X[c]+Y[d]});
			YX[k]=max({YX[c], YX[d], Y[c]+X[d]});
			XYX[k]=max({XYX[c], XYX[d], X[c]+YX[d], XY[c]+X[d]});
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
			return XYX[k];
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, q;
	string s;
	cin>>n>>q>>s;
	int m=2*(n-1);
	vi v(m+2);
	REP(i, m){
		if(s[i]=='('){
			v[i+1]=v[i]+1;
		}
		else{
			v[i+1]=v[i]-1;
		}
	}
	LazySegmentTree_max<int> lst(v, -1e9);
	cout<<lst.query(0, lst.n)<<'\n';
	int a, b;
	REP(i, q){
		cin>>a>>b;
		--a;
		--b;
		if(s[a]==s[b]){
			cout<<lst.query(0, lst.n)<<'\n';
			continue;
		}
		if(a>b){
			swap(a, b);
		}
		if(s[a]=='('){
			lst.add(a+1, b+1, -2);
		}
		else{
			lst.add(a+1, b+1, 2);
		}
		swap(s[a], s[b]);
		cout<<lst.query(0, lst.n)<<'\n';
	}
	return 0;
}
