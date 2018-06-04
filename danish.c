//Nathan Williams
//z5113658
//show danish program to print danish flag

#include <stdio.h>
#include <stdlib.h>

void showDanish (void);

int main (int argc, char *argv[]) {
 
   showDanish();
 
   return EXIT_SUCCESS;
}

void showDanish (void) {
   int row = 0;
   int col = 0;
   while (row < 5) {  
     if (row != 2) {
        while (col < 12) {
            if (col != 2) {
               printf("*");
               col = col + 1;
               }
            else
            
            if (col == 2) {
               printf(" ");
               col = col + 1;
            }
         }
      printf("\n");
      row ++;
      col = 0;

      }
   else
   
   if (row == 2) {
   printf("           ");
   printf("\n");
      row ++;
      col = 0;
   }
}      
}  
