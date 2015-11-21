LIBS = -lmraa -lupm-grove -lmosquittopp
all: main.cpp bluemix_client.cpp bluemix_client.h
	g++ main.cpp bluemix_client.cpp $(LIBS) -o main
