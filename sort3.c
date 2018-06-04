//Nathan Williams
//z5113658
//program to sort 3 numbers

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
   int first;
   int second;
   int third;
   
   scanf("%d%d%d", &first, &second, &third);
   
   if (first <= second && first <= third) {
      printf("%d\n", first);
      if (second <= third) {
         printf("%d\n%d\n", second, third);
         }
      else if (third <= second) {
         printf("%d\n%d\n", third, second);
         }
      }
   
   if (second <= first && second <= third) {
      printf("%d\n", second);
      if (third <= first) {
         printf("%d\n%d\n", third, first);
         }
      else if (first <= third) {
         printf("%d\n%d\n", first, third);
         }
      }
   
   if (third <= second && third <= first) {
      printf("%d\n", third);
      if (second <= first) {
         printf("%d\n%d\n", second, first);
         }
      else if (first <= second) {
         printf("%d\n%d\n", first, second);
         }
     }

return EXIT_SUCCESS;
}  
