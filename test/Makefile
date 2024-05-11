CC := g++
CFLAGS := -std=c++11 -Wall -Wextra -I../src -I../include -MMD -MP
LDFLAGS := -lm

TESTDIR := .
BUILDDIR := .
TESTBINDIR := $(BUILDDIR)

TESTS := $(wildcard $(TESTDIR)/*.cpp)
TESTOBJS := $(TESTS:$(TESTDIR)/%.cpp=$(BUILDDIR)/%.o)
DEPS := $(TESTOBJS:.o=.d)

CRITERION_LIB := -lcriterion

all: $(TESTBINDIR)/ratTests

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TESTBINDIR)/ratTests: $(TESTOBJS)
	$(CC) $(CFLAGS) $(TESTOBJS) $(CRITERION_LIB) $(LDFLAGS) -o $@

-include $(DEPS)

clean:
	rm -rf $(TESTBINDIR)/ratTests $(TESTOBJS) $(DEPS)

.PHONY: all clean
