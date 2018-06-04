// Nathan Williams, Ashraf Bhuiyan
// Kora16
// 08/03/16
// file to determine if integer is a leap year

#include <stdio.h>
#include <stdlib.h>

#define START_OF_GREGORIAN_CALENDAR 1583;

int year;

int main (int argx, char * argv[]) {

   printf("This program indicates whether or not a year is a leap year \n");
   
   printf("Please input a year after 1583 \n");
   
   scanf("%d", &year);
   if ((year < 1584) || (year > 214783646)) {
      printf("Please restart program and enter a valid year. \n");
         // terminates function and tells user to restart if year less than 1584,
         // ,due to leap years relying on gregorian calendar (created in 1583), or 
         // greater than 214783646 as compiler rounds numbers greater than this to 214783646.
         
   } else
       
   if ((year %4 == 0) && (year %100 != 0)){
      //satisifies divisibility by 4 and is not divisible by 100, will print and terminate
            printf("%d is a leap year! \n", year);
   } else if (year %400 == 0) {
  
      printf("%d is a leap year! \n", year);
      
   } else {
      printf("%d is not a leap year! \n", year);
   }      
return EXIT_SUCCESS;
 }
