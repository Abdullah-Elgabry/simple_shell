#include "shell.h"

/**
 * _charsz - this func will gives lpcl
 *
 * @s: pcfds
 *
 * Return: lensof mw
*/

int _charsz(char *s)
{
	int ptc;

	for (ptc = 0; s[ptc] != '\0'; ptc++)
	{
	}
	return (ptc);
}





/**
 * _charint - this fun will gives theopc
 *
 * @tgred: the ptrs
 *
 * @rot: the ptrs
 *
 * Return: 0
 *
*/






char *_charint(char *tgred, char *rot)
{
	int jk;

	for (jk = 0; rot[jk] != '\0'; jk++)
	{
		tgred[jk] = rot[jk];
	}
	tgred[jk] = rot[jk];
	return (tgred);
}





/**
 * _charlimi - this func will plc
 *
 * @rst: 1st
 * @nd: 2nd
 *
 * Return: 0 or 1
 *
*/



int _charlimi(char *rst, char *nd)
{
	int jk;

	for (jk = 0; rst[jk] == nd[jk]; jk++)
		if (rst[jk] == '\0')
			return (0);
	return (rst[jk] - nd[jk]);
}







/**
 *_charlpk - this will merged
 *
 *@tgred: fcs
 *
 *@rot: plcs
 *
 * Return: merged reslt
 *
 */




char *_charlpk(char *tgred, char *rot)
{
	int ipn, piu;

	for (ipn = 0; tgred[ipn] != '\0'; ipn++)
	{
	}


	tgred[ipn] = '/';
	ipn++;



	for (piu = 0; rot[piu] != '\0'; piu++)
	{
		tgred[ipn] = rot[piu];
		ipn++;
	}
	tgred[ipn] = '\0';
	return (tgred);
}




/**
 * char_lpk - this will goon strsa
 *
 * @klps: checks lpcsz
 *
 * @ifn: cheackers
 *
 * Return: ifthereis
 *
 **/



char *char_lpk(char *klps, const char *ifn)
{
	char *c;

	while (*klps)
	{
		while (*ifn == *klps)
		{
			klps++, ifn++;
		}
		if (*ifn == '\0')
		{
			if (*klps == '=')
			{
				klps++;
				c = klps;
				return (c);
			}
			return (NULL);
		}
		klps++;
	}
	return (NULL);
}
