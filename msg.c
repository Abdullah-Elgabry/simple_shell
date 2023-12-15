#include "shell.h"
/**
  * msg_err - this eill show if theeis anyer
  *
  * @error: the exittin
  *
  * @ruter: the ipcls
  *
  * Return: this is a vd func
  *
**/

void msg_err(int error, char **ruter)
{
	if (error == 2)
	{
		_puts(ruter[0]);
		_puts(": icannot find your dir here\n");
	}
	if (error == 1)
	{
		exit(EXIT_SUCCESS);
	}

}

