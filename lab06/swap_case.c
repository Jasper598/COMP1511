#include <stdio.h>

int swap_case(int character);

int main(void) {
 int i = 0, j;
 char ch[100];
 int c;
 c = getchar();
 while (c != EOF) {
     j = i;
  while (c != '\n') {
   ch[i++] = swap_case((int)c);
   c = getchar();
  }
  ch[i] = '\0';
  while (ch[j] != '\0') {
   putchar(ch[j++]);
  }
  printf("\n");
  c = getchar();
 }

    return 0;
}

int swap_case(int character) {
 int x = character;
    if (x >= 65 && x <= 90) {
     x += 32;
 }
 else if (x >= 97 && x <= 122) {
  x -= 32;
 }

    return x;
}
