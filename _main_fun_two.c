#include "shell.h"

/**
 * thclb - deltion thplc
 *
 * @ptr: ptraddr
 *
 *
 * Return: 0 or 1
 *
 */




int thclb(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
