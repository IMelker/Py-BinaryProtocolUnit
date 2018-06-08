All:
	g++ -c -fPIC binary_protocol.cpp -o binary_protocol.o
	g++ -shared -Wl,-soname,libbpu.so -o libbpu.so binary_protocol.o

install:
	cp *.so ../

uninstall:
	rm -f *.o *.so
	rm ../libbpu.so

clean:
	rm -f *.o *.so
