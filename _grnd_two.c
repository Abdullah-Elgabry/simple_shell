#include "shell.h"

/**
 * retn_inv - rev inv
 *
 * @dell: ptr
 *
 * Return: zero
 */


char **retn_inv(del_g *dell)
{
	if (!dell->environ || dell->env_changed)
	{
		dell->environ = lg_chs(dell->env);
		dell->env_changed = 0;
	}

	return (dell->environ);
}







/**
 * _redminv - delt char inv
 * @var: ptr
 *
 * @dell: ptr
 *
 *  Return: 0 or 1
 *
 */



int _redminv(del_g *dell, char *var)
{
	list_t *node = dell->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = beg_in(node->str, var);
		if (p && *p == '=')
		{
			dell->env_changed = rm_incs(&(dell->env), i);
			i = 0;
			node = dell->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (dell->env_changed);
}

/**
 * _ininv - brg neww inv
 *
 * @dell: ptrr
 *
 * @var: ptrval
 *
 * @value: valptr
 *
 *  Return: zero
 *
 */



int _ininv(del_g *dell, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_chrsz(var) + _chrsz(value) + 2);
	if (!buf)
		return (1);
	_chrpyy(buf, var);
	_chront(buf, "=");
	_chront(buf, value);
	node = dell->env;
	while (node)
	{
		p = beg_in(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			dell->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	nde_tofin(&(dell->env), buf, 0);
	free(buf);
	dell->env_changed = 1;
	return (0);
}

