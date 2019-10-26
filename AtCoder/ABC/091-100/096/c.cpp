#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORR(i, a, b) for(int i=b-1; i>=a; --i)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	char s[60][60];
	cin>>h>>w;
	REP(i, h+2){
		REP(j, w+2) s[i][j]='.';
	}
	REP(i, h){
		REP(j, w) cin>>s[i+1][j+1];
	}
	int dx[8]={0, 1, 0, -1, -1, 1, 1, -1};
	int dy[8]={-1, 0, 1, 0, -1, -1, 1, 1};
	bool ok=true;
	FOR(i, 1, h+1){
		FOR(j, 1, w+1){
			if(s[i][j]=='#'){
				REP(k, 8){
					if(k<=3 && s[i+dx[k]][j+dy[k]]=='#') break;
					else if(k>=4 && s[i+dx[k]][j+dy[k]]=='#'){
						ok=false;
						break;
					}
				}
			}
		}
	}
	ok ? cout<<"Yes"<<'\n' : cout<<"No"<<'\n';
	return 0;
}
