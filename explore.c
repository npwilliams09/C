//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//
 
#include <stdio.h>
#include <stdlib.h>
 
long add (int x, int y);
 
int main(int argc, const char * argv[]) {
   char c ='a';
   int x;
   int y;
   long total;
   
   unsigned long ul       = 0;
   unsigned int ui        = 1;
   unsigned long long ull = 2;
   unsigned short us      = 3;
 
   signed long sl       = 4;
   signed int si        = 5;
   signed long long sll = 6;
   signed short ss      = 7;
 
   long l       = 8;
   int i        = 9;
   long long ll = 10;
   short s      = 11;
 
   float f = 3.1;
   double d = 3.14;
   x = 40;
   y = 2;
 
   total = add (x, y);
 
   printf("the sum of %d and %d is %ld\n", x, y, total);
   
   printf("\n");
   
   printf("size of int = %zu\n", sizeof x);
   printf("size of long = %zu\n", sizeof total);
   printf("size of char = %zu\n", sizeof c);
   printf("size of long long = %zu\n", sizeof ll);
   printf("size of short = %zu\n", sizeof s);
   printf("size of float = %zu\n", sizeof f);
   printf("size of double = %zu\n", sizeof d);
   
   printf("\n");
   
   printf("size of unsigned long = %zu\n", sizeof ul);
   printf("size of unsigned int = %zu\n", sizeof si);
   printf("size of unsigned long long = %zu\n", sizeof ull);
   printf("size of unsigned short = %zu\n", sizeof us);
   printf("size of signed long = %zu\n", sizeof sl);
   printf("size of signed int = %zu\n", sizeof si);
   printf("size of signed long long = %zu\n", sizeof sll); 
   printf("size of signed short = %zu\n", sizeof ss);
 
   printf("\n");
   int*address;
   address = &x;
   printf("The address of int x is %p\n",address);
   address = &y;
   printf("The address of int y is %p\n",address);
   printf("The address of float f is %p\n",&f);
   printf("The address of unsigned long is %p\n",&ul);
   printf("\n");
  
 
   // add them all together just to make use of them so the compiler
   // doesn't grumble that they are unused in the program
 
   double grandTotal;
   grandTotal =  c +
                 ul + ui + ull + us +
                 sl + si + sll + ss +
                  l +  i +  ll +  s +
                  f + d;
 
   printf ("all these things added together make %f\n", grandTotal);
 
   return EXIT_SUCCESS;
}
 
long add (int x, int y) {
   long answer;
   answer = x + y;
 
   return answer;
}
 
