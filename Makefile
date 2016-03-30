# Makefile for compiling c++ code for The Game of Mouse
# Author: Ndivhuwo Makondo

CC := g++ -std=c++0x #The main compiler and c++0x support.

SRCDIR := src
BUILDDIR := build
TARGET := bin/test

SRCEXT := cpp
SOURCES :=  $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall
LIB := # No libraries linked
INC := -I include

.PHONY: clean

all: $(TARGET)
	@echo "Successfully compiled!"

$(TARGET): $(OBJECTS)
	@mkdir -p bin
	@echo " Linking... "
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)
