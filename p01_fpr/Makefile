CXX_FLAGS := -std=c++17 -g -w #-Ofast # Quitar -Ofast para debug y -w para los warnings
PRE_FLAGS := -MMD -MP

# Project directory structure
SRC := src
LIB := lib
INC := include
MAINFILE := $(SRC)/main.cc

# Build directories and output
TARGET := p01_fpr
BUILD := build

# Library search directories and flags
EXT_LIB :=
LDFLAGS :=
LDPATHS := $(addprefix -L,$(LIB) $(EXT_LIB))

# Include directories
INC_DIRS := $(INC) $(shell find $(SRC) -type d) 
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Construct build output and dependency filenames
SRCS := $(shell find $(SRC) -name *.cc)
OBJS := $(subst $(SRC)/,$(BUILD)/,$(addsuffix .o,$(basename $(SRCS))))
DEPS := $(OBJS:.o=.d)

# Build task
build: clean all

# Main task
all: $(TARGET)

# Task producing target from built files
$(TARGET): $(OBJS)
	@echo "🚧 Building..."
	@mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDPATHS) $(LDFLAGS)

# Compile all cc files
$(BUILD)/%.o: $(SRC)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) $(PRE_FLAGS) $(INC_FLAGS) -c -o $@ $< $(LDPATHS) $(LDFLAGS)

clean :
	@ rm -f *.o string doc
	@ rm -f p01_fpr
	@ rm -rf *~ basura b i
	@ rm -rf a.out
	@ rm -f $(OBJECTS) $(EXECUTABLE)
	@ rm -f lib/*.o
	@ find . -name '*~' -exec rm {} \;
	@ find . -name basura -exec rm {} \;

tar:
	@ tar -cvzf ../targz/p01_Adrian_Mora_Rodriguez.tar.gz .

cleanbuild:
	@ rm build/*

tarclean:
	@ rm -f ../targz/p01_Adrian_Mora_Rodriguez.tar.gz

remake :
	@ make clean
	@ rm -rf build
	@ make

git:
	@if [ -z "$(m)" ]; then \
		echo "Please provide a commit message by running: make git m=\"Your message\""; \
		exit 1; \
	fi
	@git add .
	@git commit -m "$(m)"
	@git push


