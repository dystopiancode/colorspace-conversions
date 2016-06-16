PROGNAME	= main

SRCEXT		= c
SRCDIR		= colorspace-conversions colorspace-conversions-examples
OBJDIR		= obj
BINDIR		= bin

SRCS		:= $(shell find $(SRCDIR) -name '*.$(SRCEXT)')
SRCDIRS		:= $(shell find . -name '*.$(SRCEXT)' -exec dirname {} \; | uniq)
OBJS		:= $(patsubst %.$(SRCEXT),$(OBJDIR)/%.o,$(SRCS))

DEBUG		= -g
INCLUDES	= -I./colorspace-conversions -I./colorspace-conversions-examples
CFLAGS		= -Wall -pedantic -ansi -c $(DEBUG) $(INCLUDES)
LDFLAGS		=

ifeq ($(SRCEXT), c)
CC			= $(CXX)
else
CFLAGS		+= -std=gnu99
endif

.PHONY: all clean


all: $(BINDIR)/$(PROGNAME)

$(BINDIR)/$(PROGNAME): buildrepo $(OBJS)
	@mkdir -p `dirname $@`
	@echo "Linking $@..."
	@$(CC) $(OBJS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: %.$(SRCEXT)
	@echo "Generating dependencies for $<..."
	@$(call make-depend,$<,$@,$(subst .o,.d,$@))
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) -r $(BINDIR) $(OBJDIR)

buildrepo:
	@$(call make-repo)

define make-repo
	for dir in $(SRCDIRS);				\
		do								\
			mkdir -p $(OBJDIR)/$$dir;	\
		done
endef

# usage: $(call make-depend,source-file,object-file,depend-file)
define make-depend
	$(CC)	-MM			\
			-MF $3		\
			-MP			\
			-MT $2		\
			$(CFLAGS)	\
			$1
endef