OBJS = main.cpp bluemix_client.cpp jsoncpp.cpp
HEADERS = bluemix_client.h json/json.h
LIBS = -lmraa -lupm-grove -lmosquittopp
CXXFLAGS = -std=c++11
all: $(OBJS) $(HEADERS)
	g++ $(CXXFLAGS) $(OBJS) $(LIBS) -o main
