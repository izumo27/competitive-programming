#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<n; ++i)

int main(){
	int n;
	scanf("%d", &n);
	ll l[100];
	l[0]=2;
	l[1]=1;
	REP(i, n-1){
		l[i+2]=l[i]+l[i+1];
	}
	printf("%lld\n", l[n]);
	return 0;
}
