#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int a, b, i, ans=0;
	cin>>a>>b;
	for(i=a; i<=b; i++){
		i=i;
		if((i%10)==(i/10000)%10 && (i/10)%10==(i/1000)%10) ans++;
	}
	cout<<ans<<endl;
	return 0;
}