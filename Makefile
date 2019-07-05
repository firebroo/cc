CXX=clang++
CLIENT_LDFLAGS= -Wl,-Bstatic -L/usr/local/lib -lboost_filesystem -lboost_system -lboost_thread -Wl,-Bdynamic -lpthread -lcrypto -lssl -O3 -std=c++11
INCLUDES = -I/usr/local/include/boost/
CXXFLAGS= -O3 -Wall -std=c++11 -DUSE_BOOST_REGEX
CLIENT_SOURCE=$(wildcard *.cpp)
CLIENT_OBJS=$(patsubst %.cpp,%.o, $(CLIENT_SOURCE))

%.o: %.cpp
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

client:$(CLIENT_OBJS)
	$(CXX) -o client $^ $(CLIENT_LDFLAGS) 

all: server client


.PHONY: clean
clean:
	rm -f  $(SERVER_OBJS) $(CLIENT_OBJS)  client

