all : clean test_vector test_random bench_vector

test_vector : test_vector.o vector.o
	gcc test_vector.o vector.o -g -o test_vector

test_vector.o : test_vector.c
	gcc -Wall -Wextra -g -c test_vector.c

vector.o : vector.c vector.h
	gcc -Wall -Wextra -g -c vector.c

test_random : test_random.o random.o
	gcc test_random.o random.o -g -o test_random

test_random.o : test_random.c
	gcc -Wall -Wextra -g -c test_random.c

random.o : random.c random.h
	gcc -Wall -Wextra -g -c random.c

bench_vector : bench_vector.o vector.o random.o
	gcc bench_vector.o vector.o random.o -g -o bench_vector

bench_vector.o : bench_vector.c
	gcc -Wall -Wextra -g -c bench_vector.c

clean:
	rm -f *.o
	rm -f test_vector
	rm -f test_random