proj1: proj1.o
	gcc proj1.o -g -o proj1
proj1.o: proj1.c

test: e d 
e:
	./proj1 1 zyxw original.txt encrypted.txt
d:
	./proj1 2 zyxw encrypted.txt decrypted.txt
	diff -s original.txt decrypted.txt
