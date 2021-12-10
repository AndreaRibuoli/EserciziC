all : libutf8.so

libutf8.so : converti_api.o 
	gcc -shared -o libutf8.so converti_api.o

converti_api.o : converti_api.c converti_api.h
	gcc -c -o converti_api.o converti_api.c
