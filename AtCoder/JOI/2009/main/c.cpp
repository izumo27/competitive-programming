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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, h, k, s[1333], a, b;
	pii ba[114514];
	vi v[1333];
	cin>>n>>m>>h>>k;
	REP(i, n){
		cin>>s[i];
	}
	REP(i, m){
		cin>>a>>b;
		v[b-1].push_back(a-1);
		ba[i]=pii(b-1, a-1);
	}
	int pos[1333];
	REP(i, n){
		pos[i]=i;
	}
	int pos2[1333][1333];
	REP(i, h){
		REP(j, n){
			pos2[i][j]=pos[j];
		}
		REP(j, v[i].size()){
			swap(pos[v[i][j]], pos[v[i][j]+1]);
		}
	}
	int pos3[1333];
	REP(i, n){
		pos3[pos[i]]=i;
	}
	int sum=0;
	REP(i, k){
		sum+=s[pos3[i]];
	}
	int ans=sum;
	REP(i, m){
		int c=pos2[ba[i].first][ba[i].second], d=pos2[ba[i].first][ba[i].second+1];
		if((c>=k && d>=k) || (c<k && d<k)){
			continue;
		}
		int tmp=sum;
		if(c<k){
			tmp=sum-s[pos3[c]]+s[pos3[d]];
		}
		else{
			tmp=sum-s[pos3[d]]+s[pos3[c]];
		}
		ans=min(ans, tmp);
	}
	cout<<ans<<'\n';
	return 0;
}
