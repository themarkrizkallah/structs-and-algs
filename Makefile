CXX := g++

TARGET ?= bin/exec
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cc)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -std=c++14 -Wall -Werror=vla -MMD -MP

$(TARGET): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o ${TARGET}

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
