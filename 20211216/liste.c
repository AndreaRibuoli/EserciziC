#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Elem {
  char nome[24];
  struct _Elem *pElem;  
} Elem;

int main(int argc, char *argv[]) {
  Elem *root, *last, *p;
  FILE *file;
  char riga[24];

  if (argc != 2) { 
     printf("Usage: liste <nomefile>\n"); 
     exit(-1); 
  }
  file = fopen(argv[1],"r");
  if (file == NULL) {
      printf("il file %s non esiste nella posizione indicata\n",argv[1]);
      exit(-2);
  }
  root = NULL;
  last = NULL;
  while( fgets(riga, sizeof(riga), file) != NULL) {
    p = (Elem *) malloc(sizeof(Elem));
    strncpy(p->nome, riga, strlen(riga)-1);
    p->pElem = NULL;     
    if (root == NULL) { root = p; }  
    if (last != NULL) { last->pElem = p; }
    last = p;  
  }
  fclose(file);

  p = root;
  while (p != NULL) {
    printf("%s\n", p->nome);
    p = p->pElem;  
  }  
}