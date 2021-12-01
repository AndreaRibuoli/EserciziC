/*

bash-5.1$ gcc -o cyril tabella_cyrillic.c converti_api.c
bash-5.1$ cyril 
    |0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F|
|---|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|41_|А|Б|В|Г|Д|Е|Ж|З|И|Й|К|Л|М|Н|О|П|
|42_|Р|С|Т|У|Ф|Х|Ц|Ч|Ш|Щ|Ъ|Ы|Ь|Э|Ю|Я|
|43_|а|б|в|г|д|е|ж|з|и|й|к|л|м|н|о|п|
|44_|р|с|т|у|ф|х|ц|ч|ш|щ|ъ|ы|ь|э|ю|я|

*/

#include <stdio.h>
#include <stdlib.h>

#include "converti_api.h"

int main(int argc, char *argv[]) {
   char risultato[5]; 
   printf("    "); 
   for (int c = 0; c < 16; c++)  printf("|%X", c); 
   printf("|\n|---");    
   for (int c = 0; c < 16; c++)  printf("|-"); 
   printf("|\n");    
   for (int r = 65; r < 69; r++) {
     printf("|%X_", r);  
     for (int c = 0; c < 16; c++) {
       char cyril[4];
       sprintf(cyril, "%3.3X", 16 * r + c);  
       converti_api(cyril, risultato);
       printf("|%s", risultato);
     }    
     printf("|\n");  
   }    
   return 0; 
}
