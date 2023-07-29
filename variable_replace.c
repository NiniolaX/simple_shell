#include "shell.h"
#include "main.h"

/**
 * variable_replace - Handles variable replacement in shell
 * @av: Pointer to array of shell arguments
 * Return: void
 */
void variable_replace(char ***av)
{
	int i = 0;
	char *varName, *varVal, numStr[20] = {0};
	pid_t pid;

	while ((*av)[i] != NULL)
	{
		if (av == NULL || (*av)[i] == NULL)
			return;
		if ((*av)[i][0] == '$')
		{
			varName = (*av)[i] + 1;
			if (varName[0] == '?')
			{
				_sprintf(numStr, "%d", status);
				free((*av)[i]);
				(*av)[i] = _strdup(numStr);
			}
			else if (varName[0] == '$' && varName[1] == '\0')
			{
				pid = getpid();
				_sprintf(numStr, "%d", pid);
				free((*av)[i]);
				(*av)[i] = _strdup(numStr);
			}
			else if (varName[0] == '\0')
			{
				free((*av)[i]);
				(*av)[i] = _strdup("$");
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
				{
					free((*av)[i]);
					(*av)[i] = NULL;
				}
			}
		}
		i++;
	}
}
