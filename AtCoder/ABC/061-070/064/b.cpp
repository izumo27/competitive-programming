#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int n, i, min=1000, max=0;
	cin>>n;
	int a;
	for(i=0; i<n; i++){
		cin>>a;
		if(a<min) min=a;
		if(a>max) max=a;
	}
	cout<<max-min<<endl;
	return 0;
}