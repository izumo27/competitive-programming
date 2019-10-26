#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int a, b, c, i;
	cin>>a>>b>>c;
	for(i=0; i<b; i++){
		if((i+1)*a%b==c){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
