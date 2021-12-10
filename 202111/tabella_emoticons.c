/*

U+1F600..U+1F64F

*/

#include <stdio.h>
#include <stdlib.h>

#include "converti_api.h"

int main(int argc, char *argv[]) {
   char risultato[9]; 
   for (int r = 8032; r < 8037; r++) {
     printf("|%X_", r);  
     for (int c = 0; c < 16; c++) {
       char emoticon[6];
       sprintf(emoticon, "%5.5X", 16 * r + c);  
       converti_api(emoticon, risultato);
       printf("|%s", risultato);
     }    
     printf("|\n");  
   }    
   return 0; 
}
