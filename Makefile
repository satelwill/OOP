CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra `wx-config --cxxflags`
LDLIBS=`wx-config --libs`

TARGET = exo1
SRCS   = Grille.cpp Jeu.cpp gui.cpp main.cpp
OBJS   = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDLIBS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
