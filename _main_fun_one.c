#include "shell.h"

/**
 **_gtplxc - donnot soil plcsa
 *
 *
 *@s: ptr
 *
 *
 *@b: charsa
 *
 *@n: numfn
 *
 *Return: ptr fone
 *
 */





char *_gtplxc(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}









/**
 * funfre - delations theestrs
 *
 * @pfss: pfcs
 *
 */





void funfre(char **pfss)
{
	char **a = pfss;

	if (!pfss)
		return;
	while (*pfss)
		free(*pfss++);
	free(a);
}




/**
 * blcgett - givesall plcas
 *
 * @ptr: ourtheptr
 *
 *
 * @brev_plcs: tthe ojlone
 *
 * @crc_plcs: curroneplc
 *
 *
 * Return: pointer to da ol'block nameen.
 */




void *blcgett(void *ptr, unsigned int brev_plcs, unsigned int crc_plcs)
{
	char *p;

	if (!ptr)
		return (malloc(crc_plcs));
	if (!crc_plcs)
		return (free(ptr), NULL);
	if (crc_plcs == brev_plcs)
		return (ptr);

	p = malloc(crc_plcs);
	if (!p)
		return (NULL);

	brev_plcs = brev_plcs < crc_plcs ? brev_plcs : crc_plcs;
	while (brev_plcs--)
		p[brev_plcs] = ((char *)ptr)[brev_plcs];
	free(ptr);
	return (p);
}
