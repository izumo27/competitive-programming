#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int n, i, b, ans=0;
	cin>>n;
	map<int, int> a;
	for(i=0; i<n; i++){
		cin>>b;
		a[b]++;
		if(a[b]%2) ans++;
		else ans--;
	}
	cout<<ans<<endl;
	return 0;
}