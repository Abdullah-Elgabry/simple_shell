#include "shell.h"
/**
  * main - this is the boss progrm
  *
  * Return: zeroo
  *
**/






int main(void)
{
	char *prompt = "shell$ ", *mrk = NULL, *wayto = NULL,
	**parser = NULL, *ruter = NULL;
	size_t lenremk = 0;
	int showen = 0, ret_acc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			showen = write(STDOUT_FILENO, prompt, 7);
			if (showen == -1)
			exit(0);
		}
		ret_acc = getline(&mrk, &lenremk, stdin);
		if (ret_acc == -1)
		{
			free(mrk);
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		parser = parsedd(mrk);
		if (parser[0] != NULL)
		{
			outerfun(parser, ruter, wayto, mrk);
		}
		else
			free(parser);
	}
	return (0);
}

