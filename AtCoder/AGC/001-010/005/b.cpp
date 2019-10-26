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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n;
	vi a(252525);
	cin>>n;
	REP(i, n){
		cin>>a[i];
	}
	SegmentTree_min<int> st(a);
	ll ans=0;
	REP(i, n){
		ll l1=-1, u1=i+1;
		while(u1-l1>1){
			ll mid=(l1+u1)/2;
			if(st.query(mid, i+1)==a[i]){
				u1=mid;
			}
			else{
				l1=mid;
			}
		}
		ll l2=i, u2=n+1;
		while(u2-l2>1){
			ll mid=(l2+u2)/2;
			if(st.query(i, mid+1)==a[i]){
				l2=mid;
			}
			else{
				u2=mid;
			}
		}
		// DEBUG(u1);
		// DEBUG(l2);
		ans+=a[i]*((i-u1+1)*(l2-i+1));
	}
	cout<<ans<<'\n';
	return 0;
}
