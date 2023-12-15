#include "shell.h"

/**
 * _histfun - show his
 *
 * @dell: ptr
 *
 *  Return: 0
 *
 */



int _histfun(del_g *dell)
{
	_prt_lg(dell->forg);
	return (0);
}

/**
 * alis_rev - st alis
 *
 * @dell: ptr
 *
 * @str: the tgrj stra
 *
 *
 * Return: 1 or 0
 *
 */



int alis_rev(del_g *dell, char *str)
{
	char *p, c;
	int reev;

	p = _charsloc(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	reev = rm_incs(&(dell->alias),
		fnd_thplc(dell->alias, beg_onl(dell->alias, str, -1)));
	*p = c;
	return (reev);
}

/**
 * set_alias - sets alias to string
 * @dell: ptr
 * @str: the string alias
 *
 * Return: zero on success, 1 on error
 */
int set_alias(del_g *dell, char *str)
{
	char *p;

	p = _charsloc(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (alis_rev(dell, str));

	alis_rev(dell, str);
	return (nde_tofin(&(dell->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: zero on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _charsloc(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _plankn - mimics the alias basefunc (man alias)
 * @dell: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: zero
 */
int _plankn(del_g *dell)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (dell->argc == 1)
	{
		node = dell->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; dell->argv[i]; i++)
	{
		p = _charsloc(dell->argv[i], '=');
		if (p)
			set_alias(dell, dell->argv[i]);
		else
			print_alias(beg_onl(dell->alias, dell->argv[i], '='));
	}

	return (0);
}

