#include "randrun.h"

int main() {
   int r = 0, count = 100;

   rr_init_rand(0);

   while (count) {
      r = rr_rand_lim(10);
      printf("%d\n",r);
      count--;
   }
   return(0);  
}
