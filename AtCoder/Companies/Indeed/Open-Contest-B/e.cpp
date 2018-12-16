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

const int MAX_N=114514;

// [1,n]
int bit[MAX_N+1], n;

// a_1からa_iまでの和
int bit_sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}

// a_iにxを加える
void bit_add(int i, int x){
	while(i<=n){
		bit[i]+=x;
		i+=i&-i;
	}
}

int hh[114514];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll h[114514];
	cin>>n;
	vl H;
	REP(i, n){
		cin>>h[i];
		H.push_back(h[i]);
	}
	sort(ALL(H));
	H.erase(unique(ALL(H)), H.end());
	if(H.size()!=n){
		cout<<-1<<'\n';
		return 0;
	}
	REP(i, n){
		hh[i]=lower_bound(ALL(H), h[i])-H.begin()+1;
	}
	ll ans=0;
	REP(i, n){
		ans+=h[i]*(i-bit_sum(hh[i]));
		// DEBUG(ans);
		bit_add(hh[i], 1);
	}
	cout<<ans<<'\n';
	return 0;
}
