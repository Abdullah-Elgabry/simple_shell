#include "shell.h"

/**
 * _quitfun - quittingprog
 * @dell: ptr
 *  Return: 0
 */




int _quitfun(del_g *dell)
{
	int quitti;

	if (dell->argv[1])
	{
		quitti = _msger(dell->argv[1]);
		if (quitti == -1)
		{
			dell->status = 2;
			_prt_msg(dell, "wrong invalid: ");
			_terwr(dell->argv[1]);
			chrln('\n');
			return (1);
		}
		dell->err_num = _msger(dell->argv[1]);
		return (-2);
	}
	dell->err_num = -1;
	return (-2);
}

/**
 * _cddir - cd dirr
 *
 * @dell: ptr
 *
 *  Return: 0
 */



int _cddir(del_g *dell)
{
	char *s, *plc, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!dell->argv[1])
	{
		plc = bkin(dell, "HOME=");
		if (!plc)
			chdir_ret = /* TODO: what should this be? */
				chdir((plc = bkin(dell, "PWD=")) ? plc : "/");
		else
			chdir_ret = chdir(plc);
	}
	else if (_charssim(dell->argv[1], "-") == 0)
	{
		if (!bkin(dell, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(bkin(dell, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((plc = bkin(dell, "OLDPWD=")) ? plc : "/");
	}
	else
		chdir_ret = chdir(dell->argv[1]);
	if (chdir_ret == -1)
	{
		_prt_msg(dell, "can't cd to ");
		_terwr(dell->argv[1]), chrln('\n');
	}
	else
	{
		_ininv(dell, "OLDPWD", bkin(dell, "PWD="));
		_ininv(dell, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _plhelp - plc ch
 *
 * @dell: ptr
 *
 *  Return: 0
 *
 */

int _plhelp(del_g *dell)
{
	char **arg_array;

	arg_array = dell->argv;
	_puts("fun it works \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

