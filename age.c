#include <stdio.h>

int main(int argc, char ** argv) {

   //made by Nathan Williams 2 march 2016
   //name age.c


   printf("How old are you?\n");
   int age = 0;
 
   scanf("%d", &age);
 
   printf("Your age is: %d\n", age);

   if(age < 1) {
   printf("no\n");

} else {
   if(age > 16) {

   printf("That's awesome. You can drive.\n");

} else {

   printf("lol\n");
}

   return 0;
}
