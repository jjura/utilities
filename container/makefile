BINDIR := bin
OBJDIR := obj
SRCDIR := src

BIN := $(BINDIR)/root
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CFLAGS := -Wall -Wextra -Wpedantic -std=c11
LDFLAGS :=

.PHONY: all clean

all: $(BIN)

clean:
	@rm --force $(BIN) $(OBJ)

$(BIN): $(OBJ)
	@echo "Linking: $@"
	@mkdir --parents $(BINDIR)
	@$(CC) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "-- Compiling $<"
	@mkdir --parents $(OBJDIR)
	@$(CC) -c $< -o $@ $(CFLAGS)
