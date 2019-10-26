#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
  int n, i, j = 0;
  scanf("%d", &n);
  char s[n];
  for (i = 0; i < n; i++){
    scanf("%s", &s[i]);
  }
  while (j < n) {
    if (s[j] == 'Y') break;
    j++;
  }
  if (j < n) printf("%s\n", "Four");
  else printf("%s\n", "Three");
  return 0;
}