all:
	g++ -c main.cpp
	g++ -lcurl -c generate.cpp
	g++ -lcurl -c output.cpp
	g++ -lcurl -c processing.cpp
	g++ -lcurl -c social.cpp
	g++ -lcurl -c connect.cpp
	g++ -lcurl -o lastn main.o generate.o output.o processing.o social.o connect.o
	rm main.o
	rm generate.o
	rm output.o
	rm processing.o
	rm social.o
	rm connect.o
	clear