#include <stdio.h>
#include <stdlib.h>

#include "converti_api.h"

int main(int argc, char *argv[]) {
   char risultato[5]; 
   printf("    "); 
   for (int c = 0; c < 16; c++)  printf("|-%X ", c); 
   printf("|\n");    
   for (int c = 0; c < 17; c++)  printf("|---", c); 
   printf("|\n");    
   for (int r = 2; r < 8; r++) {
     printf("| %X-", r);  
     for (int c = 0; c < 16; c++) {
       char ascii[3];
       sprintf(ascii, "%2.2X", 16 * r + c);  
       converti_api(ascii, risultato);
       printf("| %s ", risultato);
     }    
     printf("|\n");  
   }    
   return 0; 
}
