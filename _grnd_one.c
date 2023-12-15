#include "shell.h"

/**
 * cur_env - writting the cur envvv
 *
 * @dell: ptr
 *
 * Return: 0
 *
 */



int cur_env(del_g *dell)
{
	_prt_lgg(dell->env);
	return (0);
}

/**
 * bkin - back the inv
 *
 * @dell: ptr
 *
 * @name: nmofinv
 *
 *
 * Return: bllns
 */



char *bkin(del_g *dell, const char *name)
{
	list_t *node = dell->env;
	char *p;

	while (node)
	{
		p = beg_in(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * sett_inv - beg inv
 *
 * @dell: ptr
 *
 *  Return: 0
 *
 */



int sett_inv(del_g *dell)
{
	if (dell->argc != 3)
	{
		_terwr("invalid num\n");
		return (1);
	}
	if (_ininv(dell, dell->argv[1], dell->argv[2]))
		return (0);
	return (1);
}

/**
 * rminv - inv deletation
 *
 * @dell: ptr
 *
 *  Return: zero
 */




int rminv(del_g *dell)
{
	int i;

	if (dell->argc == 1)
	{
		_terwr("lest args.\n");
		return (1);
	}
	for (i = 1; i <= dell->argc; i++)
		_redminv(dell, dell->argv[i]);

	return (0);
}

/**
 * pacuk_lop - populates env linked list
 *
 * @dell: ptr
 *
 * Return: zero
 *
 */

int pacuk_lop(del_g *dell)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		nde_tofin(&node, environ[i], 0);
	dell->env = node;
	return (0);
}

