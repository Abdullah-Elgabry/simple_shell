#include "shell.h"

/**
 * retn_lg - retn the loog
 *
 * @dell: ptr
 *
 * Return: str loog
 *
 */


char *retn_lg(del_g *dell)
{
	char *buf, *plc;

	plc = bkin(dell, "HOME=");
	if (!plc)
		return (NULL);
	buf = malloc(sizeof(char) * (_chrsz(plc) + _chrsz(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_chrpyy(buf, plc);
	_chront(buf, "/");
	_chront(buf, HIST_FILE);
	return (buf);
}

/**
 * crfl - make fl to put loog init
 *
 * @dell: ptr
 *
 *
 * Return: -1 or 1
 */



int crfl(del_g *dell)
{
	ssize_t rlp;
	char *fnm = retn_lg(dell);
	list_t *node = NULL;

	if (!fnm)
		return (-1);

	rlp = open(fnm, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fnm);
	if (rlp == -1)
		return (-1);
	for (node = dell->forg; node; node = node->next)
	{
		_rtpnk(node->str, rlp);
		_wrtch('\n', rlp);
	}
	_wrtch(ALM_RG, rlp);
	close(rlp);
	return (1);
}




/**
 * lg_fndr - loog rd the tx
 *
 * @dell: ptr
 *
 *
 *
 *
 * Return: 0 or rtnfin
 *
 */



int lg_fndr(del_g *dell)
{
	int i, last = 0, invcnt = 0;
	ssize_t rlp, rdlen, leens = 0;
	struct stat st;
	char *buf = NULL, *fnm = retn_lg(dell);

	if (!fnm)
		return (0);

	rlp = open(fnm, O_RDONLY);
	free(fnm);
	if (rlp == -1)
		return (0);
	if (!fstat(rlp, &st))
		leens = st.st_size;
	if (leens < 2)
		return (0);
	buf = malloc(sizeof(char) * (leens + 1));
	if (!buf)
		return (0);
	rdlen = read(rlp, buf, leens);
	buf[leens] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(rlp);
	for (i = 0; i < leens; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			ntpop_ht(dell, buf + last, invcnt++);
			last = i + 1;
		}
	if (last != i)
		ntpop_ht(dell, buf + last, invcnt++);
	free(buf);
	dell->retlg = invcnt;
	while (dell->retlg-- >= HIST_MAX)
		rm_incs(&(dell->forg), 0);
	dfm(dell);
	return (dell->retlg);
}

/**
 * ntpop_ht - ucaan to to looga
 *
 * @dell: ptr
 *
 *
 * @buf: the buuufer
 *
 * @invcnt: msgis
 *
 *
 * Return: zero
 */



int ntpop_ht(del_g *dell, char *buf, int invcnt)
{
	list_t *node = NULL;

	if (dell->forg)
		node = dell->forg;
	nde_tofin(&node, buf, invcnt);

	if (!dell->forg)
		dell->forg = node;
	return (0);
}

/**
 * dfm - renumbers the forg linked list after changes
 * @dell: Structure containing potential arguments. Used to maintain
 *
 * Return: the curnt retlg
 */
int dfm(del_g *dell)
{
	list_t *node = dell->forg;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (dell->retlg = i);
}
