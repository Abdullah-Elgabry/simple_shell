#include "shell.h"

/**
 * hsh - the Bos funcc
 *
 * @dell: ptr
 * @lmpr: ptrvl
 *
 * Return: 1 or 0
 *
 */



int hsh(del_g *dell, char **lmpr)
{
	ssize_t r = 0;
	int getv_hm = 0;

	while (r != -1 && getv_hm != -2)
	{
		rm_deli(dell);
		if (interactive(dell))
			_puts("$ ");
		chrln(ALM_RG);
		r = nl_rtv(dell);
		if (r != -1)
		{
			begdel(dell, lmpr);
			getv_hm = srch_forr(dell);
			if (getv_hm == -1)
				srh_kls(dell);
		}
		else if (interactive(dell))
			_putchar('\n');
		delt_deli(dell, 0);
	}
	crfl(dell);
	delt_deli(dell, 1);
	if (!interactive(dell) && dell->status)
		exit(dell->status);
	if (getv_hm == -2)
	{
		if (dell->err_num == -1)
			exit(dell->status);
		exit(dell->err_num);
	}
	return (getv_hm);
}

/**
 * srch_forr - srch for bas funs
 *
 * @dell: ptr
 *
 * Return: -2 -1 0 1
 *
 */




int srch_forr(del_g *dell)
{
	int i, gv_bsfunc = -1;
	builtin_table builtintbl[] = {
		{"exit", _quitfun},
		{"env", cur_env},
		{"help", _plhelp},
		{"forg", _histfun},
		{"setenv", sett_inv},
		{"unsetenv", rminv},
		{"cd", _cddir},
		{"alias", _plankn},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_charssim(dell->argv[0], builtintbl[i].type) == 0)
		{
			dell->line_count++;
			gv_bsfunc = builtintbl[i].func(dell);
			break;
		}
	return (gv_bsfunc);
}

/**
 * srh_kls - rt fnd
 * @dell: ptr
 *
 * Return: void
 */



void srh_kls(del_g *dell)
{
	char *path = NULL;
	int i, k;

	dell->path = dell->argv[0];
	if (dell->linecount_flag == 1)
	{
		dell->line_count++;
		dell->linecount_flag = 0;
	}
	for (i = 0, k = 0; dell->arg[i]; i++)
		if (!f_rgl(dell->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = srch_rt(dell, bkin(dell, "PATH="), dell->argv[0]);
	if (path)
	{
		dell->path = path;
		poa_bsf(dell);
	}
	else
	{
		if ((interactive(dell) || bkin(dell, "PATH=")
			|| dell->argv[0][0] == '/') && chek_fd(dell, dell->argv[0]))
			poa_bsf(dell);
		else if (*(dell->arg) != '\n')
		{
			dell->status = 127;
			_prt_msg(dell, "wrong ipt\n");
		}
	}
}


/**
 * poa_bsf - pola the baseefun
 *
 * @dell: ptr
 *
 * Return: funcof void
 */



void poa_bsf(del_g *dell)
{
	pid_t child_pid;

    printf("Command path: %s\n", dell->path);

    if (access(dell->path, F_OK) == -1) {

        printf("Command doesn't exist\n");

        dell->status = 127;
        _prt_msg(dell, "Command not found\n");
        return;
    }

	child_pid = fork();
	if (child_pid == -1)
	{

		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(dell->path, dell->argv, retn_inv(dell)) == -1)
		{
			delt_deli(dell, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}

	}
	else
	{
		wait(&(dell->status));
		if (WIFEXITED(dell->status))
		{
			dell->status = WEXITSTATUS(dell->status);
			if (dell->status == 126)
				_prt_msg(dell, "sorry u cannot do this\n");
		}
	}
}

