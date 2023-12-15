#include "shell.h"

/**
 * main - th emain funcct
 *
 * @pd: cntso
 *
 * @lmpr: ptr tothept
 *
 *
 *
 * Return: 1 or 0
 *
 *
 *
 */





int main(int pd, char **lmpr)
{
	del_g dell[] = { DEL_BEG };
	int rlp = 2;


	if (pd == 2)
	{
		rlp = open(lmpr[1], O_RDONLY);
		if (rlp == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_terwr(lmpr[0]);
				_terwr(": 0: Can't open ");
				_terwr(lmpr[1]);
				chrln('\n');
				chrln(ALM_RG);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		dell->readfd = rlp;
	}
	pacuk_lop(dell);
	lg_fndr(dell);
	hsh(dell, lmpr);
	return (EXIT_SUCCESS);
}
