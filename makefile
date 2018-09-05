# Sample Make File For Project:

# Compiler and Linkers and other commands
CC 			:= g++ -pthread -std=c++11
RM			:= rm -rf

# Target Binary
TARGET 		:= test1

# Directories
SRCDIR		:= src
INCDIR		:= inc
BUILDDIR	:= obj
TARGETDIR	:= bin

# Flags, libs and Includes
CXXFLAGS	:= -c -Wall
LDFLAGS		:= 
LIB			:=
INCDIR		:= -I$(INCDIR)

# Files and Objects
# MAIN 		:= main.cpp
# DEPS		:= mutex1.h
DEPS		:= $(wildcard $(INCDIR)/*.h)
# OBJS		:= main.o mutex1.o
SRCFILES	:= $(wildcard $(SRCDIR)/*.cpp)
OBJFILES	:= $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCFILES))

# -----------------------------------------------------------------------------
#
# -----------------------------------------------------------------------------

# default make
all: directories $(TARGET)

run: clean directories $(TARGET)
	./bin/$(TARGET)

# Link - $^ is all the pre-requisites object file names
$(TARGET): $(OBJFILES)
	$(CC) $(LDFLAGS) -o $(TARGETDIR)/$@ $^

# Compile - $< is the first pre-requisite .cpp and $@ is the name of the rule
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
		$(CC) $(CXXFLAGS) $(INCDIR) -o $@ $<


# make the directories
directories:
		@mkdir -p $(TARGETDIR)
		@mkdir -p $(BUILDDIR)

# clean 
clean:
		$(RM) $(TARGETDIR) $(BUILDDIR)

# Non-File Targets
.PHONEY:
		all clean
