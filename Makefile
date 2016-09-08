CC = gcc
CXX = g++

CPPFLAGS =
CFLAGS = -c -std=c11 -Wall -Wpedantic -Wextra 
CXXFLAGS = -c -std=c++11 -Wall -Wextra -g 
BUILDDIR = build
SRCDIR = src

SOURCES = $(wildcard $(SRCDIR)/*.c $(SRCDIR)/*.cpp)
OBJECTS = $(addsuffix .o, $(notdir $(basename $(SOURCES))))

TARGET = step4

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(addprefix $(BUILDDIR)/, $(OBJECTS)) -o $@

%.o: $(SRCDIR)/%.c
	$(CC) $< -o $(BUILDDIR)/$@ $(CFLAGS) $(CPPFLAGS)

%.o: $(SRCDIR)/%.cpp
	$(CXX) $< -o $(BUILDDIR)/$@ $(CXXFLAGS) $(CPPFLAGS)
