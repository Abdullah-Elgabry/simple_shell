#include "shell.h"

/**
 * _char_inst - this func will takeinstance
 *
 * @str: trgteds
 *
 * Return: na or a ptr
 *
 */






char *_char_inst(char *str)
{
	int sizof = 0;
	char *dup;

	if (str == NULL)
		return (NULL);

	while (*str++)
		sizof++;

	dup = malloc(sizeof(char) * (sizof + 1));
	if (!dup)
		return (NULL);

	for (sizof++; sizof--;)
		dup[sizof] = *--str;

	return (dup);
}




/**
 * _beg - searcher forthe begging schar
 *
 * @klps: tgrd
 *
 * @ifn: loopertin
 *
 * Return: na or a ptr
 *
 */


char *_beg(char *klps, char *ifn)
{
	while (*ifn)
	{
		if (*ifn++ != *klps++)
			return (NULL);
	}
	return ((char *)klps);
}

/**
 * _erratoi - srt to tgted
 *
 * @s: plcrt
 *
 * Return: -1 r tgted
 *
 */





int _erratoi(char *s)
{
	int jk = 0;
	unsigned long int ret = 0;

	if (*s == '+')
		s++;

	for (jk = 0; s[jk] != '\0'; jk++)
	{
		if (s[jk] >= '0' && s[jk] <= '9')
		{
			ret *= 10;
			ret += (s[jk] - '0');
			if (ret > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}

	return (ret);
}




/**
 * mkrje - this is func to maker lpmj
 *
 * @array: [str]
 *
 * Return: lpmj
 *
 */


int mkrje(char **array)
{
	int mrkeble = 0;

	while (array[mrkeble] != NULL)
	{
		mrkeble++;
	}

	return (mrkeble);
}
