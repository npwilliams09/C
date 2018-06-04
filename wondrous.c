//Nathan Williams
//Thu Apr 14 12:14:35 2016 
// C wondrous program

#include <stdio.h>
#include <stdlib.h>
int start;
int printWondrous (int start);

int main (int argc, char *argv[]) {
   printWondrous(start);
return EXIT_SUCCESS;
}

int printWondrous (int start) {
   int steps = 1;
   printf("%d ", start);
   while (start != 1) {
      if ((start %2) == 0) {
         start = start/2;
         printf("%d ", start);
         steps++;
      }
      
      else  {
         start = (start*3) + 1;
         printf("%d ", start);
         steps++;
      }
      
   }
   printf("\n");
   return steps;
}
