#include "shell.h"

/**
 **_chrmkpy - this func will mk inscp
 *
 *
 *
 *@wyst: waytogo
 *
 *
 *@rot: wayss
 *
 *@n: numfst
 *
 *Return: strhad mergeed
 *
 *
 *
 *
 */





char *_chrmkpy(char *wyst, char *rot, int n)
{
	int i, j;
	char *s = wyst;

	i = 0;
	while (rot[i] != '\0' && i < n - 1)
	{
		wyst[i] = rot[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			wyst[j] = '\0';
			j++;
		}
	}
	return (s);
}






/**
 **_chryte - mergedstr
 *
 *
 *@wyst: strone
 *
 *
 *@rot: ndstr
 *
 *
 *@n: numfstr
 *
 *
 *Return: merged str
 *
 *
 */





char *_chryte(char *wyst, char *rot, int n)
{
	int i, j;
	char *s = wyst;

	i = 0;
	j = 0;
	while (wyst[i] != '\0')
		i++;
	while (rot[j] != '\0' && j < n)
	{
		wyst[i] = rot[j];
		i++;
		j++;
	}
	if (j < n)
		wyst[i] = '\0';
	return (s);
}




/**
 **_charsloc - this func will findstrplc
 *
 *
 *@s: covrstr
 *
 *
 *@c: fsr
 *
 *
 *Return: ptr plc
 *
 *
 */




char *_charsloc(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

