#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n, a, i, ans=0;
	int b[100010]={};
	cin>>n;
	for(i=1; i<=n; i++){
		cin>>a;
		b[a]++;
	}
	for(i=1; i<100000; i++) ans=max(ans, b[i-1]+b[i]+b[i+1]);
	cout<<ans<<endl;
	return 0;
}