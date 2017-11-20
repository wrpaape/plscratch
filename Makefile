CC       := cc
CCFLAGS  :=
LDFLAGS  := -lplplot
RM       := rm
RM_FLAGS := -f


.PHONY: all
all: plscratch

plscratch: plscratch.c plcdemos.h
	$(CC) $(CCFLAGS) $(LDFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(RM_FLAGS) plscratch
