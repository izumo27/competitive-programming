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

int in[1333];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int k=-1;
	n<<=1;
	REP(i, 1000){
		if(i*i-i==n){
			k=i;
			break;
		}
	}
	if(k==-1){
		cout<<"No"<<'\n';
		return 0;
	}
	int s[1333][1333];
	int now=1;
	REP(i, k-1){
		FOR(j, in[i], k-1){
			s[i][j]=now++;
		}
		int tmp=in[i];
		FOR(j, i+1, k){
			s[j][in[j]++]=s[i][tmp++];
		}
	}
	cout<<"Yes"<<'\n';
	cout<<k<<'\n';
	REP(i, k){
		cout<<k-1<<' ';
		REP(j, k-1){
			cout<<s[i][j]<<" \n"[j==k-2];
		}
	}
	return 0;
}
