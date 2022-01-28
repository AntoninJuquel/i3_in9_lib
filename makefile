all : clean test_vector test_random bench_vector test_vector_v2 bench_vector_v2 test_my_struct

vector.o : vector.c vector.h
	gcc -Wall -Wextra -g -c vector.c

vector_v2.o : vector.c vector.h
	gcc -Wall -Wextra -g -c vector.c -D V2 -o vector_v2.o

test_vector.o : test_vector.c
	gcc -Wall -Wextra -g -c test_vector.c

test_vector_v2.o : test_vector.c
	gcc -Wall -Wextra -g -c test_vector.c -D V2 -o test_vector_v2.o

test_vector : test_vector.o vector.o
	gcc test_vector.o vector.o -g -o test_vector

test_vector_v2 : test_vector_v2.o vector_v2.o
	gcc test_vector_v2.o vector_v2.o -g -o test_vector_v2

random.o : random.c random.h
	gcc -Wall -Wextra -g -c random.c

test_random.o : test_random.c
	gcc -Wall -Wextra -g -c test_random.c

test_random : test_random.o random.o
	gcc test_random.o random.o -g -o test_random

bench_vector.o : bench_vector.c
	gcc -Wall -Wextra -g -c bench_vector.c

bench_vector_v2.o : bench_vector.c
	gcc -Wall -Wextra -g -c bench_vector.c -D V2 -o bench_vector_v2.o

bench_vector : bench_vector.o vector.o random.o
	gcc bench_vector.o vector.o random.o -g -o bench_vector

bench_vector_v2 : bench_vector_v2.o vector_v2.o random.o
	gcc bench_vector_v2.o vector_v2.o random.o -g -o bench_vector_v2

my_struct.o : my_struct.c my_struct.h
	gcc -Wall -Wextra -g -c my_struct.c

test_my_struct.o : test_my_struct.c
	gcc -Wall -Wextra -g -c test_my_struct.c

test_my_struct : test_my_struct.o my_struct.o
	gcc test_my_struct.o my_struct.o -g -o test_my_struct

clean:
	rm -f *.o
	rm -f test_random
	rm -f test_vector
	rm -f test_vector_v2
	rm -f bench_vector
	rm -f bench_vector_v2
	rm -f test_my_struct