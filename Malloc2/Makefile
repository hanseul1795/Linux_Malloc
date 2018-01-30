GET  = memory_allocator
CC       = g++
CFLAGS   = -W -Wextra -Wall -Werror -I./includes
LINKER   = g++
LFLAGS   = -I./includes
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
SOURCES  := $(shell find $(SRCDIR) -name '*.c')
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
RM       = rm -rf
all: $(BINDIR)/$(TARGET) | $(BINDIR)
$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"
.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@echo "Cleanup complete!"
.PHONY: fclean
fclean: clean
	@$(RM) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
re  : fclean all
