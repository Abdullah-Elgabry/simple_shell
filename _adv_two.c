#include "shell.h"

/**
 * _msger - sttiint
 *
 * @s: fcsi
 *
 * Return: -1 or0
 *
 *
 *
 */






int _msger(char *s)
{
	int i = 0;
	unsigned long int otpps = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			otpps *= 10;
			otpps += (s[i] - '0');
			if (otpps > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (otpps);
}

/**
 * _prt_msg - this func will popuerr
 *
 * @dell: ptr
 * @estr: -1 or0
 *
 *
 *
 *
 */




void _prt_msg(del_g *dell, char *estr)
{
	_terwr(dell->alopf);
	_terwr(": ");
	pdect(dell->line_count, STDERR_FILENO);
	_terwr(": ");
	_terwr(dell->argv[0]);
	_terwr(": ");
	_terwr(estr);
}






/**
 * pdect - dectprt
 *
 *
 *
 * @input: findel
 *
 * @rlp: cutterfil
 *
 * Return: stridel
 *
 *
 *
 */




int pdect(int input, int rlp)
{
	int (*__putchar)(char) = _putchar;
	int i, sumin = 0;
	unsigned int _abs_, enstn;

	if (rlp == STDERR_FILENO)
		__putchar = chrln;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		sumin++;
	}
	else
		_abs_ = input;
	enstn = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + enstn / i);
			sumin++;
		}
		enstn %= i;
	}
	__putchar('0' + enstn);
	sumin++;

	return (sumin);
}






/**
 * xc_intg - thisis xchanfun
 *
 * @num: thenumbeer
 *
 * @rtobl: the bsfun
 *
 * @rmlkpo: the remableabke
 *
 *
 *
 *
 * Return: will retnthestr
 *
 */




char *xc_intg(long int num, int rtobl, int rmlkpo)
{
	static char buffer[50];
	static char *array;
	char opca = 0;
	char *ptr;
	unsigned long n = num;

	if (!(rmlkpo & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		opca = '-';

	}
	array = rmlkpo & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % rtobl];
		n /= rtobl;
	} while (n != 0);

	if (opca)
		*--ptr = opca;
	return (ptr);
}





/**
 * hsh_rmk - rmhashfun
 *
 * @buf: thptraddre
 *
 *
 *
 *
 *
 * Return: zer0
 *
 *
 *
 */




void hsh_rmk(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

