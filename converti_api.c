/*

   Autore:                  Andrea Ribuoli (2021)
   nell'ambito di:      FONDAMENTI DI PROGRAMMAZIONE
                     ITS "Magento & e-commerce software"
                     
*/

#include <stdio.h>
#include <stdlib.h>

#include "converti_api.h"

static union { char c[8]; unsigned long a_long; } test = { { 'l', '?', '?', '?', '?', '?', '?', 'b' } };
#define ENDIANNESS ((char) test.a_long)

void inverti(char *s);

int converti_api(char *CP, char *utf8) {
    char *end;
    char str[9]       = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    unsigned long *b  = (unsigned long *)(str);
    unsigned long i;
    
    i = strtol(CP, &end, 16);
    if (i <= 127) {
      *b = i;  
      if (sizeof(long)==8) {
        if (ENDIANNESS == 'l') inverti(str);  
        sprintf(utf8, "%s", &(str[sizeof(long)-1]));
      }   
    } else if (i <= 2047) {
      *b = (((i & 0x07C0) << 2) | (i & 0x003F)) | 0xC080;  
      if (sizeof(long)==8) {
        if (ENDIANNESS == 'l') inverti(str);  
        sprintf(utf8, "%s", &(str[sizeof(long)-2]));
      } 
    } else if (i <= 65535) {
      *b = (((i & 0xF000) << 4) | ((i & 0x0FC0) << 2) | (i & 0x003F)) | 0xE08080;  
      if (sizeof(long)==8) {
        if (ENDIANNESS == 'l') inverti(str);  
        sprintf(utf8, "%s", &(str[sizeof(long)-3]));
      }   
    } else {
      *b = (((i & 0x03F000) << 4) | ((i & 0x0FC0) << 2) | (i & 0x003F)) | 0xF0808080;  
      if (sizeof(long)==8) {
        if (ENDIANNESS == 'l') inverti(str);  
        sprintf(utf8, "%s", &(str[sizeof(long)-4]));
      } 
    }
    return 0; 
}

void inverti(char *s) {
  char p;
  p = s[0]; s[0] = s[7]; s[7] = p;  
  p = s[1]; s[1] = s[6]; s[6] = p;  
  p = s[2]; s[2] = s[5]; s[5] = p;  
  p = s[3]; s[3] = s[4]; s[4] = p;      
}
