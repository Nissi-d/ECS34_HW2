# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Directories
OBJDIR = obj
BINDIR = bin

# Source files and executables
SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

TESTS = teststrutils teststrdatasource teststrdatasink testdsv testxml

# Create obj and bin directories if they don't exist
$(OBJDIR) $(BINDIR):
	mkdir -p $@

# Default target to compile everything
all: $(BINDIR)/$(TESTS)

# Rule to link the object files and create executables
$(BINDIR)/teststrutils: $(OBJDIR)/StringUtils.o $(OBJDIR)/StringUtilsTest.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BINDIR)/teststrdatasource: $(OBJDIR)/StringDataSource.o $(OBJDIR)/StringDataSourceTest.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BINDIR)/teststrdatasink: $(OBJDIR)/StringDataSink.o $(OBJDIR)/StringDataSinkTest.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BINDIR)/testdsv: $(OBJDIR)/DSVReaderWriter.o $(OBJDIR)/DSVTests.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BINDIR)/testxml: $(OBJDIR)/XMLReaderWriter.o $(OBJDIR)/XMLTests.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to compile .cpp files to object files
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Execute the tests after building
run: all
	$(BINDIR)/teststrutils
	$(BINDIR)/teststrdatasource
	$(BINDIR)/teststrdatasink
	$(BINDIR)/testdsv
	$(BINDIR)/testxml

# Clean up the object and binary directories
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all run clean