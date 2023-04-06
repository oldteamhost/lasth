all:
	g++ -c main.cpp -lcurl -lssl -lcrypto
	g++ -c parse.cpp -lcurl -lssl -lcrypto
	gcc -c menu.c -lcurl -lssl -lcrypto
	gcc -c output.c -lcurl -lssl -lcrypto
	g++ -c input.cpp -lcurl -lssl -lcrypto
	gcc -c codealg.c -lcurl -lssl -lcrypto
	g++ -o lasth main.o parse.o menu.o codealg.o output.o input.o -lcurl -lssl -lcrypto
	rm -rf *.o
