#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int i, j;
	string a[4]={"dream", "dreamer", "erase", "eraser"};
	string s;
	bool can;
	cin>>s;
	reverse(s.begin(), s.end());
	for(i=0; i<4; i++) reverse(a[i].begin(), a[i].end());
	for(i=0; i<s.size();){
		can=false;
		for(j=0; j<4; j++){
			if(s.substr(i, a[j].size())==a[j]){
				can=true;
				i+=a[j].size();
			}
		}
		if(!can){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}