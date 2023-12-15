#include "shell.h"

/**
 * **rdspl - this func spstr
 *
 * @str: str tobe fcs
 *
 * @d: strcutte
 *
 * Return: nothing || ptr
 *
 *
 *
 */






char **rdspl(char *str, char *d)
{
	int fhjk = 0;
	int i, j, k, phk;
	char **s;



	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!f_rgl(str[i], d) && (f_rgl(str[i + 1], d) || !str[i + 1]))
			fhjk++;

	if (fhjk == 0)
		return (NULL);
	s = malloc((1 + fhjk) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < fhjk; j++)
	{
		while (f_rgl(str[i], d))
			i++;
		k = 0;
		while (!f_rgl(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (phk = 0; phk < k; phk++)
			s[j][phk] = str[i++];
		s[j][phk] = 0;
	}
	s[j] = NULL;
	return (s);
}




/**
 * **spltwrd - this func will hygnstr
 *
 * @str: str willbe addeed
 *
 * @d: the cuttter
 *
 * Return: nothing or ptr
 *
 *
 *
 */




char **spltwrd(char *str, char d)
{
	int fhjk = 0;
	int i, j, k, phk;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			fhjk++;
	if (fhjk == 0)
		return (NULL);
	s = malloc((1 + fhjk) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < fhjk; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (phk = 0; phk < k; phk++)
			s[j][phk] = str[i++];
		s[j][phk] = 0;
	}
	s[j] = NULL;
	return (s);
}

