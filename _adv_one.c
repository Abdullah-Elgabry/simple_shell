#include "shell.h"

/**
 * interactive - this func bre opecd bifcase
 *
 * @dell: addrptr
 *
 * Return: 0 or 1
 *
 */





int interactive(del_g *dell)
{
	return (isatty(STDIN_FILENO) && dell->readfd <= 2);
}


/**
 * f_rgl - search for onece curter
 *
 * @c: fcschar
 *
 * @cuterr: cutterplc
 *
 * Return: 0or 1
 *
 *
 *
 *
 *
 */



int f_rgl(char c, char *cuterr)
{
	while (*cuterr)
		if (*cuterr++ == c)
			return (1);
	return (0);
}





/**
 *_ceekchar - sech forr the plckly
 *
 *@c: plcas
 *
 *
 *Return: 0 or 1
 *
 */





int _ceekchar(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}






/**
 *_atoi - functo ch the pcstin
 *
 *@s: frsc
 *
 *Return: 0    or 1
 */






int _atoi(char *s)
{
	int i, opca = 1, rmkpl = 0, rst;
	unsigned int otpps = 0;

	for (i = 0;  s[i] != '\0' && rmkpl != 2; i++)
	{
		if (s[i] == '-')
			opca *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			rmkpl = 1;
			otpps *= 10;
			otpps += (s[i] - '0');
		}
		else if (rmkpl == 1)
			rmkpl = 2;
	}

	if (opca == -1)
		rst = -otpps;
	else
		rst = otpps;

	return (rst);
}
