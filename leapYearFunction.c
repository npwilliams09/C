// Nathan Williams, Ashraf Bhuiyan
// Kora16
// 08/03/16
// file to determine if integer is a leap yearand return a binary value;
// 1 for leap year and 0 if not a leap year

#include <stdio.h>
#include <stdlib.h>

#define START_OF_GREGORIAN_CALENDAR 1583;


int isLeapYear (int year);


int main (int argx, char * argv[]) {

   int i;
   int year;
   
   printf("This program indicates whether or not a year is a leap year \n");
   
   printf("Please input a year after 1583 \n");
   
   scanf("%d", &year);
   i = isLeapYear(year);
   
   if (i == 1) {
      printf("%d is a leap year! \n", year);
      }
   else {printf("%d is not a leap year! \n",year);
   }    
     
   return 0; }
   
int isLeapYear (int year) {
   
   if ((year < 1584) || (year > 214783646)) {
      printf("Please restart program and enter a valid year. \n");
         // terminates function and tells user to restart if year less than 1584,
         // ,due to leap years relying on gregorian calendar (created in 1583), or 
         // greater than 214783646 as compiler rounds numbers greater than this to 214783646.
         
   } else if ((year %4 == 0) && (year %100 != 0)){
      //satisifies divisibility by 4 and is not divisible by 100, will print and terminate
            return 1;
            
   } else if (year %400 == 0) {
      
      return 1;
      
   } else {
      
      return 0;
   }
   return EXIT_SUCCESS;
   }

        

 
