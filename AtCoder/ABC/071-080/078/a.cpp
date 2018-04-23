#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORR(i, a, b) for(int i=b-1; i>=a; --i)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	char x, y;
	cin>>x>>y;
	if(x==y){
		cout<<'='<<'\n';
		return 0;
	}
	x<y ? cout<<'<'<<'\n' : cout<<'>'<<'\n';
	return 0;
}
