#include "quiz.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int a, b;
   if (argc != 3) {
       printf("Usage: test_driver <int_a> <int_b>\n");
       exit(-1);
   } 
   a = atoi(argv[1]);
   if (a == 0) {
       printf("First argument must be an integer\n");
       exit(-2);       
   } 
   b = atoi(argv[2]); 
   if (b == 0) {
       printf("Second argument must be an integer\n");
       exit(-3);       
   } 
   printf("quiz(%i, %i) = %i\n", a, b, quiz(a,b));
   return 0;
}