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

// 素因数分解
vector<pii> prime_factor(int n){
	vector<pii> res;
	for(int i=2; i*i<=n; ++i){
		if(n%i!=0){
			continue;
		}
		int num=0;
		while(n%i==0){
			++num;
			n/=i;
		}
		res.push_back(pii(i, num));
	}
	if(n!=1){
		res.push_back(pii(n, 1));
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int n, k;
	cin>>n>>k;
	vector<pii> v=prime_factor(n);
	int cnt=0;
	for(auto x : v){
		cnt+=x.second;
	}
	if(cnt<k){
		cout<<-1<<'\n';
		return 0;
	}
	int i=0, tmp=1;
	cnt=0;
	for(auto x : v){
		if(cnt>=k-1){
			break;
		}
		if(cnt+x.second>=k-1){
			for(cnt; cnt<k-1; ++cnt){
				cout<<x.first<<' ';
				tmp*=x.first;
			}
		}
		else{
			REP(i, x.second){
				cout<<x.first<<' ';
				tmp*=x.first;
				++cnt;
			}
		}
	}
	cout<<n/tmp<<'\n';
	return 0;
}
