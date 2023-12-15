#include "shell.h"

/**
 * check_linki -  cheks linking between bufffs
 *
 * @dell: ptr
 *
 * @buf: ptr
 *
 * @p: the posss addr
 *
 *
 * Return: 1or 0
 *
 */



int check_linki(del_g *dell, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		dell->cmd_buf_type = BS_CH;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		dell->cmd_buf_type = BS_ALK;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		dell->cmd_buf_type = BS_LINK;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * how_lkd - dep on st
 *
 * @dell: ptr
 *
 * @buf: ptr
 *
 * @p: pos addr
 *
 *
 * @i: beggingio
 *
 * @szfb: sizeofsj
 *
 * Return: this is vd func
 *
 */



void how_lkd(del_g *dell, char *buf, size_t *p, size_t i, size_t szfb)
{
	size_t j = *p;

	if (dell->cmd_buf_type == BS_ALK)
	{
		if (dell->status)
		{
			buf[i] = 0;
			j = szfb;
		}
	}
	if (dell->cmd_buf_type == BS_CH)
	{
		if (!dell->status)
		{
			buf[i] = 0;
			j = szfb;
		}
	}

	*p = j;
}

/**
 * als_exc - exchange als to str
 *
 * @dell: ptr
 *
 * Return: 1 or 0
 *
 */



int als_exc(del_g *dell)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = beg_onl(dell->alias, dell->argv[0], '=');
		if (!node)
			return (0);
		free(dell->argv[0]);
		p = _charsloc(node->str, '=');
		if (!p)
			return (0);
		p = _mkcoop(p + 1);
		if (!p)
			return (0);
		dell->argv[0] = p;
	}
	return (1);
}




/**
 * ex_ch - exchanges chars
 *
 * @dell: ptr
 *
 * Return: 1 or 0
 */


int ex_ch(del_g *dell)
{
	int i = 0;
	list_t *node;

	for (i = 0; dell->argv[i]; i++)
	{
		if (dell->argv[i][0] != '$' || !dell->argv[i][1])
			continue;

		if (!_charssim(dell->argv[i], "$?"))
		{
			xch_ch(&(dell->argv[i]),
				_mkcoop(xc_intg(dell->status, 10, 0)));
			continue;
		}
		if (!_charssim(dell->argv[i], "$$"))
		{
			xch_ch(&(dell->argv[i]),
				_mkcoop(xc_intg(getpid(), 10, 0)));
			continue;
		}
		node = beg_onl(dell->env, &dell->argv[i][1], '=');
		if (node)
		{
			xch_ch(&(dell->argv[i]),
				_mkcoop(_charsloc(node->str, '=') + 1));
			continue;
		}
		xch_ch(&dell->argv[i], _mkcoop(""));

	}
	return (0);
}




/**
 * xch_ch - xchang strrk
 *
 * @ropap: str possg
 *
 * @curnt: the behj
 *
 * Return: 1 or 0
 */
int xch_ch(char **ropap, char *curnt)
{
	free(*ropap);
	*ropap = curnt;
	return (1);
}
