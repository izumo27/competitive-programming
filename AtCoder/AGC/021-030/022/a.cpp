#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int i, j;
	int a[100];
	string s;
	cin>>s;
	int len=s.size();
	if(s=="zyxwvutsrqponmlkjihgfedcba"){
		cout<<"-1"<<endl;
		return 0;
	}
	else if(len!=26){
		char ans;
		bool flag=false;
		string c("abcdefghijklmnopqrstuvwxyz");
		for(j=0; j<26; j++){
			flag=false;
			for(i=0; i<len; i++){
				if(c[j]==s[i]) flag=true;
			}
			if(!flag){
				ans=c[j];
				break;
			}
		}
		for(i=0; i<len; i++) cout<<s[i];
		cout<<ans<<endl;
		return 0;
	}
	else{
		int num;
		for(i=25; i>=1; i--){
			if(s[i-1]<s[i]){
				num=i;
				break;
			}
		}
		string t=s.substr(num);
		sort(t.begin(), t.end());
		char ans;
		int tlen=t.size();
		for(i=0; i<tlen; i++){
			if(t[i]>s[num-1]){
				ans=t[i];
				break;
			}
		}
		for(i=0; i<num-1; i++) cout<<s[i];
		cout<<ans<<endl;
		return 0;
	}
}