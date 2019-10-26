#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int n, i, ans=0;
	bool oddflag=false;
	cin>>n;
	int a[n];
	for(i=0; i<n; i++){
		cin>>a[i];
	}
	while(true){
		for(i=0; i<n; i++){
			if(a[i]%2!=0){
				oddflag=true;
			}
		}
		if(oddflag){
			break;
		}
		ans++;
		for(i=0; i<n; i++){
			a[i]/=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}