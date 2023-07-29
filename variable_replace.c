#include "shell.h"
#include "main.h"

/**
 * variable_replace - Handles variable replacement in shell
 * @av: Pointer to array of shell arguments
 * Return: void
 */
int variable_replace(char ***av)
{
	int i = 0;
	char *varName, *varVal, numStr[20] = {0};
	pid_t pid;

	while ((*av)[i] != NULL)
	{
		if (av == NULL || (*av)[i] == NULL)
			return (0);
		if ((*av)[i][0] == '$')
		{
			varName = (*av)[i] + 1;
			if (varName[0] == '?')
			{
				_sprintf(numStr, "%d", status);
				free((*av)[i]);
				(*av)[i] = _strdup(numStr);
				return (0);
			}
			else if (varName[0] == '$' && varName[1] == '\0')
			{
				pid = getpid();
				_sprintf(numStr, "%d", pid);
				free((*av)[i]);
				(*av)[i] = _strdup(numStr);
				return (0);
			}
			else
			{
				varVal = _getenv(varName);
				if (varVal != NULL)
				{
					free((*av)[i]);
					(*av)[i] = _strdup(varVal);
				}
				else
					return (-1);
			}
		}
		i++;
	}
	return (0);
}
