OBJS = main.cpp bluemix_client.cpp jsoncpp.cpp
LIBS = -lmraa -lupm-grove -lmosquittopp -lupm-groveloudness -lupm-servo
CXXFLAGS = -std=c++11
all: $(OBJS)
	g++ $(CXXFLAGS) $(OBJS) $(LIBS) -o main
