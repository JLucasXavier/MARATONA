#include <ctype.h>
#include <stdio.h>

int string2num (char *s, int base) {
  int tmp=10;
  int a = 0;
  for (; *s; s++)
    if(isdigit(*s)){
        a = a*base + (*s - '0');
       
    }else{
        tmp= (*s-'a')+tmp;
       a = a*base + tmp;
       tmp=10;
    }
  return a;
}

int main (void) {
    printf("%d\n", string2num("1a", 16));
    printf("%d\n", string2num("a09b", 16));
    printf("%d\n", string2num("z09b", 36));
    return 0;
}