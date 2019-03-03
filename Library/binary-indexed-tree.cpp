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

template<typename T> inline void CHMAX(T& a, const T b) {if(a>b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a<b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const int MAX_N=114514;

template<typename T> struct BinaryIndexedTree{
	// [1,n]
	int n;
	vector<T> bit;

	BinaryIndexedTree(int n_=1, T d=0){
		init(n_, d);
	}

	void init(int n_=1, T d=0){
		n=n_;
		bit.resize(n+1);
		REP(i, n+1){
			bit[i]=d;
		}
	}

	// a_1からa_iまでの和
	T sum(int i){
		T s=bit[0];
		while(i>0){
			s+=bit[i];
			i-=i&-i;
		}
		return s;
	}

	// a_iにxを加える
	void add(int i, T x){
		while(i<=n){
			bit[i]+=x;
			i+=i&-i;
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
