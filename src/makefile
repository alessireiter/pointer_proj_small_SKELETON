CFLAGS = -Wall

#target exe
all: pointer_proj_small.o fileio.o stringmanip.o
	g++ $(CFLAGS) -o myexe pointer_proj_small.o fileio.o stringmanip.o
	
#rebuild if the files below change

fileio.o: ../fileio/fileio.cpp ../includes/fileio.h ../includes/constants.h
	g++ $(CFLAGS) -c ../fileio/fileio.cpp
	
stringmanip.o: ../parser/stringmanip.cpp ../includes/stringmanip.h ../includes/constants.h
	g++ $(CFLAGS) -c ../parser/stringmanip.cpp

pointer_proj_small.o: pointer_proj_small.cpp
	g++ $(CFLAGS) -c ../src/pointer_proj_small.cpp 
	

#type 'make clean' to remove following	
clean:
	rm -f *.o myexe

