#include <stdio.h>
int main() {
  int t1 = 0, t2 = 1, nextTerm = 0, n,i=2;
  printf("Enter a positive number: ");
  scanf("%d", &n);

  // displays the first two terms which is always 0 and 1
  printf("Fibonacci Series: %d, %d, ", t1, t2);
  nextTerm = t1 + t2;

  while (nextTerm <= n) {
    printf("%d, ", nextTerm);
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
    ++i;
  }
  
  printf("\n");
  printf("index %d",i);
  return 0;
}
