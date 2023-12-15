#include "shell.h"

/**
 * mem_cal - this func will colthemem
 *
 * @ptr: ptrr
 *
 * @st_plc: unsig prte
 *
 * @cur_plc: siz to be gen
 *
 *
 * Return: null or 0
 *
*/

void *mem_cal(void *ptr, unsigned int st_plc, unsigned int cur_plc)
{
	void *mem;
	char *plc_inst, *contl;
	unsigned int plc;

	if (cur_plc == st_plc)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(cur_plc);

		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (cur_plc == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	plc_inst = ptr;
	mem = malloc(sizeof(*plc_inst) * cur_plc);

	if (mem == NULL)
	{
		free(ptr);
		return (NULL);

	}
	contl = mem;

	for (plc = 0; plc < st_plc && plc < cur_plc; plc++)
		contl[plc] = *plc_inst++;

	free(ptr);
	return (mem);
}
