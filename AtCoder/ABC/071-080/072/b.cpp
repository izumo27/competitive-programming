#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int len, i;
	string s;
	cin>>s;
	len=s.length();
	string t((len+1)/2, '0');
	for(i=0; i<len; i++){
		if(i%2==0){
			t[i/2]=s[i];
		}
	}
	cout<<t<<endl;
	return 0;
}