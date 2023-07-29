#ifndef MEMTRACKER_HEADER
#define MEMTRACKER_HEADER

#include <stdlib.h>
#include "shell.h"

extern char *memtracker[100];
extern char **memtrackerH;
extern int trackerSize;

void free_tracked_memory(void);
#endif
