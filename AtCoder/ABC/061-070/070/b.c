#include <stdio.h>

int main() {
  int a,b,c,d;
  scanf("%d%d%d%d", &a, &b, &c, &d);

  if (a > c) c = a;
  if (b > d) b = d;
  if (c < b) printf("%d\n", b-c);
  else printf("0\n");
  return 0;
}