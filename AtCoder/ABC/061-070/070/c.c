#include <stdio.h>

long long int gcd(long long int a,long long int b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

long long int lcm(long long int a, long long int b) {
  long long int g = gcd(a, b);
  return a/g*b;
}

// long long int lcms(long long int *a, int n) {
//   int i;
//   long long int ans;
//   ans = 1;
//   for (i=0; i<n; i++) {
//     ans = lcm(ans, a[i]);
//   }
//   return ans;
// }

int main() {
  int n,i;
  scanf("%d", &n);
  long long int t[n];
  for (i=0; i<n; i++) {
    scanf("%lld", &t[i]);
  }
  long long int ans;
  ans = 1;
  for (i=0; i<n; i++) {
    ans = lcm(ans, t[i]);
  }
  printf("%lld\n", ans);
  return 0;
}