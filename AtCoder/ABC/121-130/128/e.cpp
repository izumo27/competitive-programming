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

constexpr int INF=1<<30;

template<typename T> struct LazySegmentTree_min{
	int n;
	vector<T> node, lazy;
	vector<bool> lazyflag;
	T MAX;

	LazySegmentTree_min(const int& n_=1, const T& MAX_=INT_MAX){
		init(n_, MAX_);
	}

	// nodeの初期化
	void init(const int& n_, const T& MAX_){
		// int n_=v.size();
		n=1;
		while(n<n_){
			n<<=1;
		}
		node.resize(n*2-1);
		lazy.resize(n*2-1, INF);
		lazyflag.resize(n*2-1, false);
		MAX=MAX_;
		REP(i, n_){
			node[i+n-1]=MAX;
		}
		FORR(i, 0, n-1){
			node[i]=min(node[i*2+1], node[i*2+2]);
		}
	}

	// k番目(0-indexed)を遅延評価
	void eval(int k, int l, int r){
		// 遅延配列が空なら子へ伝搬しない
		if(!lazyflag[k]){
			return;
		}
		node[k]=lazy[k];
		// 最下段でなければ伝搬
		if(r-l>1){
			lazy[k*2+1]=lazy[k*2+2]=lazy[k];
			lazyflag[k*2+1]=lazyflag[k*2+2]=true;
		}
		lazyflag[k]=false;
	}

	// // k番目(0-indexed)をaに変更
	// void update(int k, const T &a){
	// 	k+=n-1;
	// 	node[k]=a;
	// 	while(k>0){
	// 		k=(k-1)/2;
	// 		node[k]=min(node[k*2+1], node[k*2+2]);
	// 	}
	// }


	// k: 節点の番号、その節点は[l, r)に対応づく
	void update(int a, int b, const T &x, int k, int l, int r){
		eval(k, l, r);
		// [a, b)と[l, r)が交差しなければ何もしない
		if(r<=a || b<=l){
			return;
		}
		// [a, b)と[l, r)が完全に含んでいれば遅延配列に値を入れて評価
		if(a<=l && r<=b){
			lazy[k]=x;
			lazyflag[k]=true;
			eval(k, l, r);
		}
		// そうでなければ子を再帰的に計算し更新
		else{
			update(a, b, x, k*2+1, l, (l+r)/2);
			update(a, b, x, k*2+2, (l+r)/2, r);
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

	void update(int a, int b, const T &x){
		update(a, b, x, 0, 0, n);
	}

	T query(int a, int b){
		return query(a, b, 0, 0, n);
	}
};

int n, q;

int compress(int *x1, int *x2, int *x3){
	vi xs;
	REP(i, n){
		xs.push_back(x1[i]);
		xs.push_back(x2[i]);
	}
	REP(i, q){
		xs.push_back(x3[i]);
	}
	// xs.push_back(0);
	// xs.push_back(max(n, q));
	sort(ALL(xs));
	xs.erase(unique(ALL(xs)), xs.end());
	REP(i, n){
		x1[i]=lower_bound(ALL(xs), x1[i])-xs.begin();
		x2[i]=lower_bound(ALL(xs), x2[i])-xs.begin();
	}
	REP(i, q){
		x3[i]=lower_bound(ALL(xs), x3[i])-xs.begin();
	}
	return xs.size();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int s, t, x[252521], d[252521], sx[252521], tx[252521];
	cin>>n>>q;
	REP(i, n){
		cin>>s>>t>>x[i];
		sx[i]=max(0, s-x[i]);
		tx[i]=max(0, t-x[i]);
	}
	REP(i, q){
		cin>>d[i];
	}
	int m=compress(sx, tx, d);
	pair<int, pii> stx[252521];
	REP(i, n){
		stx[i]=make_pair(x[i], pii(sx[i], tx[i]));
	}
	sort(stx, stx+n);
	reverse(stx, stx+n);
	LazySegmentTree_min<int> lst(m, INF);
	REP(i, n){
		lst.update(stx[i].second.first, stx[i].second.second, stx[i].first);
		// DEBUG(sx[i]);
		// DEBUG(tx[i]);
	}
	REP(i, q){
		int ans=lst.query(d[i], d[i]+1);
		if(ans==INF){
			cout<<-1<<'\n';
		}
		else{
			cout<<ans<<'\n';
		}
	}
	return 0;
}
