CC      := clang
CFLAGS  := -g -Wall -Ilib/glib -Ilib/glib/glib
LDFLAGS := -Llib/glib/glib/.libs
LIBS    := -lglib-2.0

SOURCES := $(shell find src -type f -name *.c)
OBJECTS := $(patsubst src/%,build/%,$(SOURCES:.c=.o))
DEPS    := $(OBJECTS:.o=.deps)
TARGET  := game

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "  Linking..."; $(CC) $(LDFLAGS) $^ -o $(TARGET) $(LIBS)

build/%.o: src/%.c | init
	@echo "  CC $<"; $(CC) $(CFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<

init:
	@mkdir -p build

clean:
	@echo "  Cleaning..."; $(RM) -r build $(TARGET)

glib:
	cd lib/glib && configure && $(MAKE)

clean-glib:
	@echo "  Cleaning glib..."; cd lib/glib && $(MAKE) clean

-include $(DEPS)

.PHONY: all init clean glib clean-glib
