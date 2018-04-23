#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORR(i, a, b) for(int i=b-1; i>=a; --i)

string a[20];
string b[20];
bool ok;

void dfs(int i, int j){
	if(i<0 || i>=10 || j<0 || j>=10) return;
	if(b[i][j]=='x') return;
	b[i][j]='x';
	dfs(i-1, j);
	dfs(i+1, j);
	dfs(i, j-1);
	dfs(i, j+1);
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string> a(20);
	REP(i, 10){
		cin>>a[i];
	}
	REP(i, 10){
		REP(j, 10){
			REP(k, 10) b[k]=a[k];
			if(b[i][j]=='x'){
				int count=0;
				b[i][j]='o';
				REP(k, 10){
					REP(l, 10){
						if(b[k][l]=='o'){
							dfs(k, l);
							count++;
						}
					}
				}
				if(count==1){
					ok=true;
					i=10;
					j=10;
				}
			}
		}
	}
	ok ? cout<<"YES"<<'\n' : cout<<"NO"<<'\n';
	return 0;
}
