main: main.o imageio.o invertcolors.o
	g++ -o main main.o imageio.o invertcolors.o

main.o: main.cpp imageio.h invertcolors.h
	g++ -c main.cpp

invertcolors.o: invertcolors.cpp invertcolors.h
	g++ -c invertcolors.cpp

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

clean:
	rm -f sample.o imageio.o main.o invertcolors.o
