#include "shell.h"

/**
 * _chrsz - get thesize
 *
 * @s: fcsstr
 *
 *
 * Return: int telsthesiz
 *
 *
 *
 */


int _chrsz(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}




/**
 * _charssim - find thesmili
 *
 * @frst: 1ststr
 *
 * @ndo: 2ndstr
 *
 *
 *
 * Return: - or +
 *
 *
 *
 */




int _charssim(char *frst, char *ndo)
{
	while (*frst && *ndo)
	{
		if (*frst != *ndo)
			return (*frst - *ndo);
		frst++;
		ndo++;
	}
	if (*frst == *ndo)
		return (0);
	else
		return (*frst < *ndo ? -1 : 1);
}







/**
 * beg_in - sechefor st
 *
 * @glfind: fcs str
 *
 * @wants: fcs fnd
 *
 * Return: nothing or stadd
 *
 *
 *
 */




char *beg_in(const char *glfind, const char *wants)
{
	while (*wants)
		if (*wants++ != *glfind++)
			return (NULL);
	return ((char *)glfind);
}





/**
 * _chront - merge strs
 *
 * @wyst: thefin plc
 *
 * @rot: waytoget
 *
 *
 * Return: the outptr
 *
 *
 *
 */




char *_chront(char *wyst, char *rot)
{
	char *reev = wyst;

	while (*wyst)
		wyst++;
	while (*rot)
		*wyst++ = *rot++;
	*wyst = *rot;
	return (reev);
}

