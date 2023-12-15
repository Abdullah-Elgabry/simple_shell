#include "shell.h"

/**
 * at_thest - atthe st
 *
 * @pltis: ptrtoad
 *
 * @str: ptrtn
 *
 *
 * @num: naklei
 *
 *
 *
 * Return: the lenlst
 *
 */



list_t *at_thest(list_t **pltis, const char *str, int num)
{
	list_t *hd_fc;

	if (!pltis)
		return (NULL);
	hd_fc = malloc(sizeof(list_t));
	if (!hd_fc)
		return (NULL);
	_gtplxc((void *)hd_fc, 0, sizeof(list_t));
	hd_fc->num = num;
	if (str)
	{
		hd_fc->str = _mkcoop(str);
		if (!hd_fc->str)
		{
			free(hd_fc);
			return (NULL);
		}
	}
	hd_fc->next = *pltis;
	*pltis = hd_fc;
	return (hd_fc);
}



/**
 * nde_tofin - aaddfin
 *
 * @pltis: stratptr
 *
 * @str: flstra
 *
 * @num: dxi
 *
 *
 * Return: the llsn
 */




list_t *nde_tofin(list_t **pltis, const char *str, int num)
{
	list_t *nde_plc, *node;

	if (!pltis)
		return (NULL);

	node = *pltis;
	nde_plc = malloc(sizeof(list_t));
	if (!nde_plc)
		return (NULL);
	_gtplxc((void *)nde_plc, 0, sizeof(list_t));
	nde_plc->num = num;
	if (str)
	{
		nde_plc->str = _mkcoop(str);
		if (!nde_plc->str)
		{
			free(nde_plc);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = nde_plc;
	}
	else
		*pltis = nde_plc;
	return (nde_plc);
}





/**
 * _prt_lgg - restri funal
 *
 * @h: the ourtr
 *
 *
 * Return: lstd
 *
 */



size_t _prt_lgg(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}










/**
 * rm_incs - rmthe ixplc
 *
 * @pltis: ptrop
 *
 * @index: fcslpr
 *
 *
 * Return: 0 or 1
 */
int rm_incs(list_t **pltis, unsigned int index)
{
	list_t *node, *bast_lp;
	unsigned int i = 0;

	if (!pltis || !*pltis)
		return (0);

	if (!index)
	{
		node = *pltis;
		*pltis = (*pltis)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *pltis;
	while (node)
	{
		if (i == index)
		{
			bast_lp->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		bast_lp = node;
		node = node->next;
	}
	return (0);
}

/**
 * rm_thelst - rmthe listt
 *
 * @fc_plat: ptraddrei
 *
 *
 * Return: this  is voidfunc
 */




void rm_thelst(list_t **fc_plat)
{
	list_t *node, *nde_onel, *pltis;

	if (!fc_plat || !*fc_plat)
		return;
	pltis = *fc_plat;
	node = pltis;
	while (node)
	{
		nde_onel = node->next;
		free(node->str);
		free(node);
		node = nde_onel;
	}
	*fc_plat = NULL;
}
