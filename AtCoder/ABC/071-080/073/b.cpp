#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int n, i, ans=0;
	cin>>n;
	int l, r;
	for(i=0; i<n; i++){
		cin>>l>>r;
		ans+=r-l+1;
	}
	cout<<ans<<endl;
	return 0;
}