#include "memtracker.h"

/**
 * free_tracked_memory - Frees tracked dynamically allocated pointers
 *
 * Return: void
 */
void free_tracked_memory(void)
{
	int i;

	for (i = 0; i < trackerSize; i++)
	{
		if (memtracker[i] != NULL)
			free(memtracker[i]);
	}
	if (memtrackerH != NULL)
		free(memtrackerH);
	if (aliasTracker != NULL)
		free(aliasTracker);
}
