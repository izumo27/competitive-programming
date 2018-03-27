#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int n, y, a, b, c;
	cin>>n>>y;
	for(a=0; a<=n; a++){
		for(b=0; b<=n-a; b++){
			c=n-a-b;
			if(10000*a+5000*b+1000*c==y){
				cout<<a<<" "<<b<<" "<<c<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<" "<<-1<<" "<<-1<<endl;
	return 0;
}