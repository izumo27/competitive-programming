#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<n; ++i)

int main(){
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  printf("%d\n", min(n*a, b));
  return 0;
}
