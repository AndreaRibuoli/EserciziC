all: sub-make emoticons cyril ascii    

sub-make: 
	make -C myapi
    
emoticons : tabella_emoticons.o 
	gcc -o emoticons -L./myapi -lutf8 tabella_emoticons.o

cyril : tabella_cyrillic.o
	gcc -o cyril -L./myapi -lutf8 tabella_cyrillic.o
    
ascii : tabella_ascii.o    
	gcc -o ascii -L./myapi -lutf8 tabella_ascii.o
    
tabella_emoticons.o : tabella_emoticons.c 
	gcc -c -I./myapi -o tabella_emoticons.o tabella_emoticons.c
    
tabella_cyrillic.o : tabella_cyrillic.c 
	gcc -c -I./myapi -o tabella_cyrillic.o tabella_cyrillic.c
    
tabella_ascii.o : tabella_ascii.c 
	gcc -c -I./myapi -o tabella_ascii.o tabella_ascii.c
