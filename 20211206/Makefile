all: sub-make test_driver    

sub-make: 
	make -C math_api
    
test_driver : test_driver.o 
	gcc -o test_driver -L./math_api test_driver.o -lmath

test_driver.o : test_driver.c 
	gcc -c -I./math_api -o test_driver.o test_driver.c
