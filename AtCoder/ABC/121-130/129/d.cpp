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

int cnt[2525][2525], cnt2[2525][2525];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int h, w;
	char s[2525][2525];
	cin>>h>>w;
	FOR(i, 1, h+1){
		FOR(j, 1, w+1){
			cin>>s[i][j];
		}
	}
	REP(i, h+2){
		s[i][0]=s[i][w+1]='#';
	}
	REP(i, w+2){
		s[0][i]=s[h+1][i]='#';
	}
	h+=2;
	w+=2;
	REP(i, h){
		int tmp=0, fst=0;
		REP(j, w){
			if(s[i][j]=='.'){
				++tmp;
			}
			if(s[i][j]=='#'){
				FOR(k, fst, j){
					cnt[i][k]=tmp;
				}
				tmp=0;
				fst=j+1;
			}
		}
	}
	REP(i, w){
		int tmp=0, fst=0;
		REP(j, h){
			if(s[j][i]=='.'){
				++tmp;
			}
			if(s[j][i]=='#'){
				FOR(k, fst, j){
					cnt2[k][i]=tmp;
				}
				tmp=0;
				fst=j+1;
			}
		}
	}
	int ans=0;
	REP(i, h){
		REP(j, w){
			if(cnt[i][j]>0 && cnt[i][j]>0){
				CHMAX(ans, cnt[i][j]+cnt2[i][j]-1);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
