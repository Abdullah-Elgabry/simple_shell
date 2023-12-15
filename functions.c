#include "shell.h"
/**
  * _ret_inv - this is will rereve inv
  *
  * @name: nameof the sklp
  *
  * Return: this is will rer tpl
  *
**/






char *_ret_inv(char *name)
{
	char *bsd;
	int jk = 0;

	while (*environ[jk] != '\0')
	{
		bsd = char_lpk(environ[jk], name);

		if (bsd == NULL)
			jk++;

		else
			return (bsd);

	}
	return (NULL);
}





/**
  * parsedd - this will pardes
  *
  * @mrk: the rupl
  *
  * Return: [str]
  *
**/



char **parsedd(char *mrk)
{
	int prs, jk = 0;
	char *pres, **pars_pr;

	prs = accwrd(mrk);

	if (prs == 0)
		return (NULL);

	pres = strtok(mrk, CUTTER);
	pars_pr = malloc(sizeof(char *) * (prs + 1));

	while (pres != NULL)
	{
		pars_pr[jk] = malloc(sizeof(char) * (_charsz(pres) + 1));
		pars_pr[jk] = _charint(pars_pr[jk], pres);
		pres = strtok(NULL, CUTTER);
		jk++;
	}
	pars_pr[jk] = NULL;
	return (pars_pr);
}

/**
 * clear_fn - this will clears allmem
 *
 * @scl: [str]
 *
 * Return: this isvd func
 *
**/







void clear_fn(char **scl)
{
	int jk;

	for (jk = 0; scl[jk] != NULL ; jk++)
	{
		free(scl[jk]);
	}
	free(scl);
}





/**
 * outfun - this will outputh the func
 *
 * @prs: [parseeed]
 *
 * @ways: way to
 *
 * Return: this is vdfucn
 *
**/





char  *outfun(char **prs, char *ways)
{
	char *pres = NULL, *aftero = NULL, *timeed = NULL;
	const char s[2] = ":";
	struct stat ix;

	if (stat(prs[0], &ix) == 0)
	{
		aftero = malloc(sizeof(char) * (_charsz(prs[0]) + 1));
		aftero = _charint(aftero, prs[0]);
		return (aftero);
	}
	else
	{
		timeed = malloc(sizeof(char) * (_charsz(ways) + 1));
		timeed = _charint(timeed, ways);
		pres = strtok(timeed, s);

		while (pres != NULL)
		{
			aftero = malloc(sizeof(char) * (_charsz(pres) + _charsz(prs[0]) + 2));
			aftero = _charint(aftero, pres);
			aftero = _charlpk(aftero, prs[0]);
			if (stat(aftero, &ix) == 0)
			{
				return (aftero);
			}
			pres = strtok(NULL, s);
			free(aftero);
		}
		free(timeed);
	}
	return (NULL);
}

