/*

   Autore:                  Andrea Ribuoli (2021)
   nell'ambito di:      FONDAMENTI DI PROGRAMMAZIONE
                     ITS "Magento & e-commerce software"
                     
*/

#include <stdio.h>
#include <stdlib.h>

static union { char c[8]; unsigned long a_long; } test = { { 'l', '?', '?', '?', '?', '?', '?', 'b' } };
#define ENDIANNESS ((char) test.a_long)

int converti(char *CP);
void inverti(char *s);

int main(int argc, char *argv[]) {
   for (int c = 1; c < argc; c++)
     converti(argv[c]);    
   return 0; 
}

int converti(char *CP) {
    char *end;
    char str[9]       = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    unsigned long *b  = (unsigned long *)(str);
    unsigned long i;
    
    i = strtol(CP, &end, 16);
    printf("U+%8.8lX ", i);
    if (i <= 127) {
      printf("[U+0000 -  U+007F] ");   
      *b = i;  
      printf("UTF-8:       %2.2lX ", *b);
      if (sizeof(long)==8) {
        if (ENDIANNESS == 'l') inverti(str);  
        printf("'%s'\n", &(str[sizeof(long)-1]));
      } else printf("\n");  
    } else if (i <= 2047) {
      printf("[U+0080 -  U+07FF] ");   
      *b = (((i & 0x07C0) << 2) | (i & 0x003F)) | 0xC080;  
      printf("UTF-8:     %4.4lX ", *b);
      if (sizeof(long)==8) {
        if (ENDIANNESS == 'l') inverti(str);  
        printf("'%s'\n", &(str[sizeof(long)-2]));
      } else printf("\n");  
    } else if (i <= 65535) {
      printf("[U+0800 -  U+FFFF] ");   
      *b = (((i & 0xF000) << 4) | ((i & 0x0FC0) << 2) | (i & 0x003F)) | 0xE08080;  
      printf("UTF-8:   %6.6lX ", *b);
      if (sizeof(long)==8) {
        if (ENDIANNESS == 'l') inverti(str);  
        printf("'%s'\n", &(str[sizeof(long)-3]));
      } else printf("\n");  
    } else {
      printf("[U+10000-U+10FFFF] ");   
      *b = (((i & 0x03F000) << 4) | ((i & 0x0FC0) << 2) | (i & 0x003F)) | 0xF0808080;  
      printf("UTF-8: %8.8lX ", *b);
      if (sizeof(long)==8) {
        if (ENDIANNESS == 'l') inverti(str);  
        printf("'%s'\n", &(str[sizeof(long)-4]));
      } else printf("\n");  
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
