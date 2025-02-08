CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra 

OBJDIR = obj
BINDIR = bin

SRCS = StringUtils.cpp StringUtilsTest.cpp
OBJS = $(OBJDIR)/StringUtils.o $(OBJDIR)/StringUtilsTest.o
TARGET = $(BINDIR)/teststrutils

# create directories if nonexistent
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# build object files
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# link executable
$(TARGET): $(OBJS) | $(BINDIR)
	$(CXX) $(OBJS) -lgtest -lgtest_main -pthread -o $(TARGET)

# run 
test: $(TARGET)
	$(TARGET)

# clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)
