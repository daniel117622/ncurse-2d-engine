# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Output program name
TARGET = program

# Source files
SRCS = main.cpp initialization.cpp text_utils.cpp background.cpp

# For object files in build/
OBJDIR = build
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Default target: compile only
all: $(TARGET)

build: all

# Link step (build executable)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lncursesw

# Compile each .cpp to build/*.o -- auto-create build/ if missing
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: all
	./$(TARGET)

clean:
	rm -rf $(OBJDIR) $(TARGET)