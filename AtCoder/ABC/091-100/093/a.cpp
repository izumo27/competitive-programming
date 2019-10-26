#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin>>s;
  sort(begin(s), end(s));
  s=="abc" ? cout<<"Yes"<<endl : cout<<"No"<<endl;
  return 0;
}
