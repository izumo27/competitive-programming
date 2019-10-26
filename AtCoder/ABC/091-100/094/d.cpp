#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  int a[110000];
  cin>>n;
  for(int i=0; i<n; i++) cin>>a[i];
  sort(a, a+n);
  int ans1=a[n-1], ans2=0;
  for(int i=0; i<n; i++){
    if(min(ans1-ans2, ans1-(ans1-ans2))<min(ans1-a[i], ans1-(ans1-a[i]))) ans2=a[i];
  }
  cout<<ans1<<' '<<ans2<<endl;
  return 0;
}
