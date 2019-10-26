#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int a, b, c, d;
  cin>>a>>b>>c>>d;
  if(a+b>c+d) cout<<"Left"<<endl;
  if(a+b==c+d) cout<<"Balanced"<<endl;
  if(a+b<c+d) cout<<"Right"<<endl;
  return 0;
}
