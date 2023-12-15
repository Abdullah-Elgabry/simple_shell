#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>


#define BUFFER_PLC 1024
#define SHW_PLC 1024
#define RMK_PLC -1


void msg_err(int errnum, char **parser);
int siz_cntr(char *sent);
int accwrd(char *text);
int _putchar(char c);
char *_charch(char *s, char c);
char *_charint(char *tgred, char *rot);
int _charsz(char *s);
int _charlimi(char *rst, char *nd);
char *_charlpk(char *tgred, char *rot);
char *char_lpk(char *klps, const char *ifn);
char *_memset(char *s, char piu, unsigned int n);
void *mem_cal(void *ptr, unsigned int st_plc, unsigned int cur_plc);
void outerfun(char **parser, char *ruter, char *wayto, char *mrk);
void _puts(char *str);
char *_ret_inv(char *name);
char **parsedd(char *mrk);
void clear_fn(char **scl);
char  *outfun(char **prs, char *ways);

#define CUTTER " ,!¡¿?\'\"\n\t"

extern char **environ;

#endif
