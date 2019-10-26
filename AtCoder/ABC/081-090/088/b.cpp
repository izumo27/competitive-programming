#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int n, i, alice=0, bob=0;
  cin>>n;
  int a[n];
  for(i=0; i<n; i++) cin>>a[i];
  sort(a, a+n, greater<int>());
  for(i=0; i<n; i+=2){
    alice+=a[i];
  }
  for(i=1; i<n; i+=2){
    bob+=a[i];
  }
  cout<<alice-bob<<endl;
  return 0;
}