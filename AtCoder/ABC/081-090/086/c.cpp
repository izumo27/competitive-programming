#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n, i, dt, dst;
	int t[100009], x[100009], y[100009];
	bool can=true;
	cin>>n;
	for(i=0; i<n; i++) cin>>t[i+1]>>x[i+1]>>y[i+1];
	for(i=0; i<n; i++){
		dt=t[i+1]-t[i];
		dst=abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
		if(dt<dst || dst%2!=dt%2) can=false;
	}
	can ? cout<<"Yes"<<endl : cout<<"No"<<endl;
	return 0;
}