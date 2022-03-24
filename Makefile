main: main.o imageio.o taskfuncs.o
	g++ -o main main.o imageio.o taskfuncs.o

main.o: main.cpp imageio.h taskfuncs.h
	g++ -c main.cpp

taskfuncs.o: taskfuncs.cpp taskfuncs.h
	g++ -c taskfuncs.cpp

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

clean:
	rm -f sample.o imageio.o main.o taskfuncs.o
