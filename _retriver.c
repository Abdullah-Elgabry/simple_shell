#include "shell.h"

/**
 * thpl_de - cmds to the bffs
 *
 * @dell: ptr
 *
 * @buf: addre
 *
 * @szfb: ptradrre
 *
 *
 * Return: the nmi to wtcaf
 *
 *
 */



ssize_t thpl_de(del_g *dell, char **buf, size_t *szfb)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*szfb)
	{

		free(*buf);
		*buf = NULL;
		signal(SIGINT, edatfun);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _lineret(dell, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			dell->linecount_flag = 1;
			hsh_rmk(*buf);
			ntpop_ht(dell, *buf, dell->retlg++);



			{
				*szfb = r;
				dell->bs_plc = buf;
			}
		}
	}
	return (r);
}

/**
 * nl_rtv - retn the nls to mes
 *
 * @dell: ptr
 *
 *
 * Return: nms berd
 *
 */




ssize_t nl_rtv(del_g *dell)
{
	static char *buf;
	static size_t i, j, szfb;
	ssize_t r = 0;
	char **buf_p = &(dell->arg), *p;

	_putchar(ALM_RG);
	r = thpl_de(dell, &buf, &szfb);
	if (r == -1)
		return (-1);
	if (szfb)
	{
		j = i;
		p = buf + i;

		how_lkd(dell, buf, &j, i, szfb);
		while (j < szfb)
		{
			if (check_linki(dell, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= szfb)
		{
			i = szfb = 0;
			dell->cmd_buf_type = BS_DEF;
		}

		*buf_p = p;
		return (_chrsz(p));
	}

	*buf_p = buf;
	return (r);
}

/**
 * dgg_mb - this will rdmybf
 *
 *
 * @dell: ptr
 *
 * @buf: mybf
 *
 * @i: thleng
 *
 *
 * Return: nasd
 *
 */




ssize_t dgg_mb(del_g *dell, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(dell->readfd, buf, PLC_FUNC);
	if (r >= 0)
		*i = r;
	return (r);
}





/**
 * _lineret - retnf mes the lpod
 *
 * @dell: ptr
 *
 *
 * @ptr: pttr addre
 *
 * @sz: the leng
 *
 * Return: 0
 */



int _lineret(del_g *dell, char **ptr, size_t *sz)
{
	static char buf[PLC_FUNC];
	static size_t i, szfb;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *mls = NULL, *c;

	p = *ptr;
	if (p && sz)
		s = *sz;
	if (i == szfb)
		i = szfb = 0;

	r = dgg_mb(dell, buf, &szfb);
	if (r == -1 || (r == 0 && szfb == 0))
		return (-1);

	c = _charsloc(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : szfb;
	mls = blcgett(p, s, s ? s + k : k + 1);
	if (!mls)
		return (p ? free(p), -1 : -1);

	if (s)
		_chryte(mls, buf + i, k - i);
	else
		_chrmkpy(mls, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = mls;

	if (sz)
		*sz = s;
	*ptr = p;
	return (s);
}

/**
 * edatfun - nt fnaloc
 *
 * @sakl: n f the oldy
 *
 *
 * Return: navodd fun
 *
 *
 */



void edatfun(__attribute__((unused))int sakl)
{
	_puts("\n");
	_puts("$ ");
	_putchar(ALM_RG);
}
