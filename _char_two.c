#include "shell.h"

/**
 * _chrpyy - this func will cpstr
 *
 * @wyst: the way togo
 *
 *
 *
 * @rot: the sorce
 *
 * Return: den ptrr
 *
 */


char *_chrpyy(char *wyst, char *rot)
{
	int i = 0;

	if (wyst == rot || rot == 0)
		return (wyst);
	while (rot[i])
	{
		wyst[i] = rot[i];
		i++;
	}
	wyst[i] = 0;
	return (wyst);
}

/**
 * _mkcoop - strto makecoop
 *
 * @str: str fcsd
 *
 *
 *
 * Return: outptr
 *
 *
 *
 */






char *_mkcoop(const char *str)
{
	int sz = 0;
	char *reev;

	if (str == NULL)
		return (NULL);
	while (*str++)
		sz++;
	reev = malloc(sizeof(char) * (sz + 1));
	if (!reev)
		return (NULL);
	for (sz++; sz--;)
		reev[sz] = *--str;
	return (reev);
}




/**
 *_puts - prt str
 *
 *@str: targeteet stri
 *
 * Return: na
 *
 */



void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - show chr
 *
 * @c: targertd str
 *
 *
 * Return: 1 or 0
 */





int _putchar(char c)
{
	static int i;
	static char buf[PRT_PLCS];

	if (c == ALM_RG || i >= PRT_PLCS)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != ALM_RG)
		buf[i++] = c;
	return (1);
}

