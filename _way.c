#include "shell.h"

/**
 * chek_fd - checksthe fdfile
 *
 * @dell: ptrr
 *
 * @path: the way to reach
 *
 *
 *
 * Return: 0 0r 1
 */






int chek_fd(del_g *dell, char *path)
{
	struct stat st;

	(void)dell;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}





/**
 * cpy_strs - this funwill makeacoppy
 *
 * @pathstr: waystr
 *
 * @begfrm: beggin
 *
 * @end: endsplc
 *
 *
 *
 * Return: the ptrs
 *
 *
 *
 */




char *cpy_strs(char *pathstr, int begfrm, int end)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = begfrm; i < end; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}




/**
 * srch_rt - srchfrthe way
 *
 * @dell: ptrs
 *
 *
 * @pathstr: waystr
 *
 * @resher: tsercher
 *
 *
 *
 * Return: iffind retenthe way
 *
 */



char *srch_rt(del_g *dell, char *pathstr, char *resher)
{
	int i = 0, nw_plc = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_chrsz(resher) > 2) && beg_in(resher, "./"))
	{
		if (chek_fd(dell, resher))
			return (resher);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = cpy_strs(pathstr, nw_plc, i);
			if (!*path)
				_chront(path, resher);
			else
			{
				_chront(path, "/");
				_chront(path, resher);
			}
			if (chek_fd(dell, path))
				return (path);
			if (!pathstr[i])
				break;
			nw_plc = i;
		}
		i++;
	}
	return (NULL);
}
