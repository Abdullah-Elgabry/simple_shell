#include "shell.h"


/**
 * accwrd - this will be a rmkb
 *
 * @str: fcsa
 *
 * Return: klpmbs
 *
**/



int accwrd(char *str)
{
	int plc = 0;
	int sents = 0;
	int len = 0;

	for (plc = 0; *(str + plc); plc++)
		len++;
	for (plc = 0; plc < len; plc++)
	{
		if (*(str + plc) != ' ')
		{
			sents++;
			plc += siz_cntr(str + plc);
		}
	}
	return (sents);
}





/**
 * siz_cntr - ths will retve lpmc
 *
 * @sent: the tgred
 * Return: lp
 *
**/



int siz_cntr(char *sent)
{
	int sizof = 0;

	while (*sent != '\0' && (*sent) != ' ')
	{
		sizof++;
		sent++;
	}
	return (sizof);
}



/**
 * _puts - func will showns
 *
 * @str: fcsa
 *
 * Return: na because itsvd
 *
*/

void _puts(char *str)
{
		int ptc;

		ptc = 0;
		while (*(str + ptc) != '\0')
		{
			_putchar(str[ptc]);
			ptc++;
		}
}








/**
 * _charch - finderplc
 *
 * @s: fcsal
 *
 * @c: plc
 *
 * Return: 0 or ptr
 *
*/



char *_charch(char *s, char c)
{
	int jk;

	for (jk = 0; s[jk] != '\0'; jk++)
	{
		if (c == s[jk])
		return (s + jk);
	}

		if (c == s[jk])
		return (s + jk);

	return (NULL);
}










/**
 * _putchar - this will be a shownstr
 *
 * @c: trg planshyt
 *
 * Return: str bent
 *
 */



int _putchar(char c)
{
	return (write(1, &c, 1));
}
