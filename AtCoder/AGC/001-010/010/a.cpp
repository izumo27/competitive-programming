#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n, a, i, ans=0;
	cin>>n;
	for(i=0; i<n; i++){
		cin>>a;
		if(a%2!=0) ans++;
	}
	if(ans%2==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}