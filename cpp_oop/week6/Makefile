CXX := g++
CXXFLAGS := -g -Wall -Wextra  --std=c++11 -O3 
SRCS := $(wildcard *.cc)
PROGS := $(patsubst %.cc,%,$(SRCS))

.PHONY: all clean
all: $(PROGS)

%: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)