#include <stdio.h>
 
int main() {
 int i = 0, cnt[26] = {0}, sum = 0;
 int c;
 c = getchar();
 while (c != EOF) {
  while (c != '\n') {
   if (c >= 'A' && c <= 'Z'){
    c += 32;
    cnt[c - 97] += 1;
    sum++;
   }
   else if (c >= 'a' && c <= 'z') {
    cnt[c - 97] += 1;
    sum++;
   }
   c = getchar();
   if(c==-1){
      break;
    }
  }
  c = getchar();
 }
 while (i < 26) {
  printf("'%c'  %.6f  %d\n", i + 97, 1.00 * cnt[i] / sum, cnt[i]);
  i++;
 }
 
 return 0;
}
