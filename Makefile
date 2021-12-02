all : emoticons cyril ascii

emoticons : tabella_emoticons.o converti_api.o     
	gcc -o emoticons tabella_emoticons.o converti_api.o
    
cyril : tabella_cyrillic.o converti_api.o
	gcc -o cyril tabella_cyrillic.o converti_api.o
    
ascii : tabella_ascii.o converti_api.o     
	gcc -o ascii tabella_ascii.o converti_api.o
    
tabella_ascii.o : tabella_ascii.c converti_api.h
	gcc -c -o tabella_ascii.o tabella_ascii.c
    
tabella_cyrillic.o : tabella_cyrillic.c converti_api.h
	gcc -c -o tabella_cyrillic.o tabella_cyrillic.c
    
tabella_emoticons.o : tabella_emoticons.c converti_api.h
	gcc -c -o tabella_emoticons.o tabella_emoticons.c
    
converti_api.o : converti_api.c converti_api.h
	gcc -c -o converti_api.o converti_api.c
