#include <queue/queue.h>
int main() {
  int i = 0;
  printf("Enter 5 elements:");
  for (; i < 5; ++i) {
    int k = 0;
    scanf("%d", &k);
    push(k);
  }

  printf("Elements in queue are:");
  for (i = 0; i < 5; i++) {
    printf("%d\t", pop());
  }
  return 0;
}
