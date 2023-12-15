#include "shell.h"
/**
 * outerfun - exe the pro
 *
 * @parser: addr
 *
 * @ruter: rulrert
 *
 * @mrk: ptra
 *
 * @wayto: Tour lop fcs
 *
 * Return: this is vd func
 *
 **/
void outerfun(char **parser, char *ruter, char *wayto, char *mrk)
{
	int child_pid = 0, status, exitstatus = 0;

	if (parser[0] != NULL && (_charlimi(parser[0], "exit") == 0))
	{
		_puts("\n");
		clear_fn(parser);
		free(mrk);
		exit(0);
	}
	wayto = _ret_inv("PATH");
	ruter = outfun(parser, wayto);
	if (ruter != NULL)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			return;
		}
		if (child_pid == 0)
		{
		execve(ruter, parser, environ);
		}
		free(ruter);
		wait(&status);
		if (WIFEXITED(status))
		{
		exitstatus = WEXITSTATUS(status);
		}
	}
	else
		msg_err(2, parser);
	(void)exitstatus;
	clear_fn(parser);
}

