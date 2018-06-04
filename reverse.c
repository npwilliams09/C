//reverse  a string
//by Nathan Williams

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


char * reverse (char * message);

int main(int argc, char *argv[]) {
    char array[20];
    char temp = 0;
    int i = 0;
    temp = getchar();
    while (temp != -1) {
        array[i] = temp;
        i++;
        temp = getchar();
    }
    array[i-1] ='\0';
    printf("%s\n", array);
    
    char *reversed = reverse(array);
    //assert(strcmp(reverse("comp"), "pmoc") == 0);
    int j = 0;
    while ( j < strlen(reversed)) {
        j++;
    }
    printf("%s\n", reversed);
    free (reversed);
    return EXIT_SUCCESS;
}


char *reverse (char *message) {
    int strLength = strlen(message) - 1;
    char *reversed = malloc(strLength);
    int i = 0;
    int j = strLength;
    while (i < j) {
        reversed[i] = message[strLength];
        i++;
        strLength--;
    }
    reversed[i] = message [strLength];
    reversed[i+1] = '\0';
    //free (reversed);
    return reversed;
}
