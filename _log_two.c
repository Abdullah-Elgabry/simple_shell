#include "shell.h"

/**
 * sz_flst - chesack sthelop
 *
 * @h: pointer to first node
 *
 *
 *
 *
 * Return: lstzs
 *
 */





size_t sz_flst(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}








/**
 * lg_chs - giveu arrof mak
 *
 * @pltis: the pret
 *
 *
 * Return: [] srt
 *
 *
 */





char **lg_chs(list_t *pltis)
{
	list_t *node = pltis;
	size_t i = sz_flst(pltis), j;
	char **strs;
	char *str;

	if (!pltis || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_chrsz(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _chrpyy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * _prt_lg - _prt plat idolg
 *
 * @h: ptr
 *
 *
 * Return: ls dioplaobn
 *
 */





size_t _prt_lg(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(xc_intg(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}









/**
 * beg_onl - givs the stnames
 *
 * @node: the ourptr
 *
 * @nxton: smilopy
 *
 * @c: numnxt
 *
 *
 *
 * Return: similty
 *
 */





list_t *beg_onl(list_t *node, char *nxton, char c)
{
	char *p = NULL;

	while (node)
	{
		p = beg_in(node->str, nxton);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * fnd_thplc - find the plc
 *
 * @pltis: threptr
 *
 * @node: the ptrnds
 *
 *
 * Return: -1 or the plcas
 *
 */




ssize_t fnd_thplc(list_t *pltis, list_t *node)
{
	size_t i = 0;

	while (pltis)
	{
		if (pltis == node)
			return (i);
		pltis = pltis->next;
		i++;
	}
	return (-1);
}
