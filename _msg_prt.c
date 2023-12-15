#include "shell.h"

/**
 *_terwr - charsprt
 *
 * @str: fcs str
 *
 *
 * Return: na
 *
 */



void _terwr(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		chrln(str[i]);
		i++;
	}
}

/**
 * chrln - show strs in lkp
 *
 * @c: fcs strwill
 *
 *
 *
 * Return: 1 or 0
 */



int chrln(char c)
{
	static int i;
	static char buf[PRT_PLCS];

	if (c == ALM_RG || i >= PRT_PLCS)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != ALM_RG)
		buf[i++] = c;
	return (1);
}

/**
 * _wrtch - prt ch st
 *
 * @c: fcs ch
 *
 * @rlp: dlen
 *
 *
 * Return: 0 or 1
 *
 */


int _wrtch(char c, int rlp)
{
	static int i;
	static char buf[PRT_PLCS];

	if (c == ALM_RG || i >= PRT_PLCS)
	{
		write(rlp, buf, i);
		i = 0;
	}
	if (c != ALM_RG)
		buf[i++] = c;
	return (1);
}

/**
 *_rtpnk - prt str
 *
 * @str: fcs str
 *
 *
 * @rlp: fl fcs
 *
 *
 * Return: num of the hpl
 *
 */



int _rtpnk(char *str, int rlp)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _wrtch(*str++, rlp);
	}
	return (i);
}
