CXX			= g++
CXXFLAGS	= -std=c++11 -c -g -Wall
LDFLAGS		= -L/usr/lib/x86_64-linux-gnu/ -lyaml-cpp
SOURCES		= hike_main.cpp compute_time.cpp
OBJECTS		= $(SOURCES:.cpp=.o)
EXECUTABLE	= bridge
INCLUDES	= hike_main.h

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) $(INCLUDES)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
