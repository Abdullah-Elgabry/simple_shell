#include "shell.h"

/**
 * rm_deli - statr thenew onc
 *
 * @dell: ptradd
 *
 */



void rm_deli(del_g *dell)
{
	dell->arg = NULL;
	dell->argv = NULL;
	dell->path = NULL;
	dell->argc = 0;
}

/**
 * begdel - beginn withthe sta
 *
 * @dell: addrptr
 *
 * @lmpr: ptrlmp
 */






void begdel(del_g *dell, char **lmpr)
{
	int i = 0;

	dell->alopf = lmpr[0];
	if (dell->arg)
	{
		dell->argv = rdspl(dell->arg, " \t");
		if (!dell->argv)
		{

			dell->argv = malloc(sizeof(char *) * 2);
			if (dell->argv)
			{
				dell->argv[0] = _mkcoop(dell->arg);
				dell->argv[1] = NULL;
			}
		}
		for (i = 0; dell->argv && dell->argv[i]; i++)
			;
		dell->argc = i;

		als_exc(dell);
		ex_ch(dell);
	}
}






/**
 * delt_deli -  clearsall
 *
 * @dell: addrptr
 *
 * @holf: boool
 *
 *
 */


void delt_deli(del_g *dell, int holf)
{
	funfre(dell->argv);
	dell->argv = NULL;
	dell->path = NULL;
	if (holf)
	{
		if (!dell->bs_plc)
			free(dell->arg);
		if (dell->env)
			rm_thelst(&(dell->env));
		if (dell->forg)
			rm_thelst(&(dell->forg));
		if (dell->alias)
			rm_thelst(&(dell->alias));
		funfre(dell->environ);
			dell->environ = NULL;
		thclb((void **)dell->bs_plc);
		if (dell->readfd > 2)
			close(dell->readfd);
		_putchar(ALM_RG);
	}
}

