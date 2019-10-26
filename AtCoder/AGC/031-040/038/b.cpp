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

template<typename T> struct SegmentTree_max{
	int n;
	vector<T> node;
	T MIN;

	SegmentTree_max(const vector<T> &v, const T &MIN_=0){
		init(v, MIN_);
	}

	// n要素で初期化
	void init(const vector<T> &v, const T &MIN_){
		int n_=v.size();
		n=1;
		while(n<n_){
			n<<=1;
		}
		node.resize(n*2-1);
		MIN=MIN_;
		REP(i, n_){
			node[i+n-1]=v[i];
		}
		FORR(i, 0, n-1){
			node[i]=max(node[i*2+1], node[i*2+2]);
		}
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

	// [a, b)の最大値を求める
	// k: 節点の番号、その節点は[l, r)に対応づく
	T query(int a, int b, int k, int l, int r){
		// [a, b)と[l, r)が交差しなければMIN
		if(r<=a || b<=l){
			return MIN;
		}
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

	T query(int a, int b){
		return query(a, b, 0, 0, n);
	}
};

template<typename T> struct SegmentTree_min{
	int n;
	vector<T> node;
	T MAX;

	SegmentTree_min(const vector<T> &v, const T &MAX_=INT_MAX){
		init(v, MAX_);
	}

	// n要素で初期化
	void init(const vector<T> &v, const T &MAX_=INT_MAX){
		int n_=v.size();
		n=1;
		while(n<n_){
			n<<=1;
		}
		node.resize(n*2-1);
		MAX=MAX_;
		REP(i, n_){
			node[i+n-1]=v[i];
		}
		FORR(i, 0, n-1){
			node[i]=min(node[i*2+1], node[i*2+2]);
		}
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

	// [a, b)の最小値を求める
	// k: 節点の番号、その節点は[l, r)に対応づく
	T query(int a, int b, int k, int l, int r){
		// [a, b)と[l, r)が交差しなければMAX
		if(r<=a || b<=l){
			return MAX;
		}
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

	T query(int a, int b){
		return query(a, b, 0, 0, n);
	}
};

bool f[252525];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, k;
	cin>>n>>k;
	vi p(n);
	REP(i, n){
		cin>>p[i];
	}
	int idx=0;
	while(idx<n){
		int cnt=1;
		while(idx<n-1 && p[idx]<p[idx+1]){
			++idx;
			++cnt;
			if(cnt>=k){
				f[idx]=true;
				// DEBUG(idx);
			}
			// DEBUG(cnt);
		}
		++idx;
	}
	SegmentTree_max<int> st1(p);
	SegmentTree_min<int> st2(p);
	int ans=n-k+1;
	bool same=false;
	if(f[k-1]){
		same=true;
	}
	FOR(i, k, n){
		if(f[i]){
			if(!same){
				same=true;
			}
			else{
				--ans;
			}
			continue;
		}
		// DEBUG(st1.query(i-k, i+1));
		// DEBUG(st2.query(i-k, i+1));
		if(st1.query(i-k, i+1)==p[i] && st2.query(i-k, i+1)==p[i-k]){
			--ans;
		}
		// DEBUG(ans);
	}
	cout<<ans<<'\n';
	return 0;
}
