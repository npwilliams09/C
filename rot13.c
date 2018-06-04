// Nathan Williams, Ashraf Bhuiyan
// Kora16
// 22/03/16
// roti13 decoder

#include <stdio.h>
#include <stdlib.h>

char encode (char letter);


int main (int argx, char * argv[]) {
   char letter = 0;
   encode(letter);

return EXIT_SUCCESS;
}   

char encode (char letter) {
      letter += 13;
      printf("%c", letter);
      return letter;
}
