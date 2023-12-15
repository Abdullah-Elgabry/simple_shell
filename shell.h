#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define PLC_FUNC 1024
#define PRT_PLCS 1024
#define ALM_RG -1

#define BS_DEF		0
#define BS_CH		1
#define BS_ALK		2
#define BS_LINK		3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct progdelta - this holest find
 *
 *
 *@arg: str willbe gen
 *
 *@argv: [] atrs
 *
 *@path: way togo
 *
 *@argc: lpanj alp scl
 *
 *@line_count: counter
 *
 *@err_num: msg poped
 *
 *@linecount_flag: flagmarkable slpc
 *
 *@alopf: the idenfiwr
 *
 *@env: thinv namklop
 *
 *@environ: this is for useage perso
 *
 *@forg: lg frthe lp
 *
 *@alias: anname forthelp
 *
 *@env_changed: checksisl
 *
 *@status: getting flg
 *
 *@bs_plc: ptraddre
 *
 *@cmd_buf_type: sortation metd
 *
 *@readfd: glppreader
 *
 *@retlg: lnto be srted
 *
 */






typedef struct progdelta
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *alopf;
	list_t *env;
	list_t *forg;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **bs_plc;
	int cmd_buf_type;
	int readfd;
	int retlg;
} del_g;

#define DEL_BEG \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct basefunc - basefunc allbelongs
 *
 *
 *@type: the rmkabel
 *
 *
 *@func: our onwvofumc
 */


typedef struct basefunc
{
	char *type;
	int (*func)(del_g *);
} builtin_table;


ssize_t nl_rtv(del_g *);
int _lineret(del_g *, char **, size_t *);
void edatfun(int);

int check_linki(del_g *, char *, size_t *);
void how_lkd(del_g *, char *, size_t *, size_t, size_t);
int als_exc(del_g *);
int ex_ch(del_g *);
int xch_ch(char **, char *);


void _terwr(char *);
int chrln(char);
int _wrtch(char c, int rlp);
int _rtpnk(char *str, int rlp);

int _chrsz(char *);
int _charssim(char *, char *);
char *beg_in(const char *, const char *);
char *_chront(char *, char *);

char *_chrpyy(char *, char *);
char *_mkcoop(const char *);
void _puts(char *);
int _putchar(char);

char *_chrmkpy(char *, char *, int);
char *_chryte(char *, char *, int);
char *_charsloc(char *, char);

char **rdspl(char *, char *);
char **spltwrd(char *, char);

char *_gtplxc(char *, char, unsigned int);
void funfre(char **);
void *blcgett(void *, unsigned int, unsigned int);




int hsh(del_g *, char **);
int srch_forr(del_g *);
void srh_kls(del_g *);
void poa_bsf(del_g *);



int thclb(void **);

int interactive(del_g *);
int f_rgl(char, char *);
int _ceekchar(int);
int _atoi(char *);

void rm_deli(del_g *);
void begdel(del_g *, char **);
void delt_deli(del_g *, int);

int _msger(char *);
void _prt_msg(del_g *, char *);
int pdect(int, int);
char *xc_intg(long int, int, int);
void hsh_rmk(char *);

int _quitfun(del_g *);
int _cddir(del_g *);
int _plhelp(del_g *);

int _histfun(del_g *);
int _plankn(del_g *);


int chek_fd(del_g *, char *);
char *cpy_strs(char *, int, int);
char *srch_rt(del_g *, char *, char *);




char *bkin(del_g *, const char *);
int cur_env(del_g *);
int sett_inv(del_g *);
int rminv(del_g *);
int pacuk_lop(del_g *);

char **retn_inv(del_g *);
int _redminv(del_g *, char *);
int _ininv(del_g *, char *, char *);

char *retn_lg(del_g *dell);
int crfl(del_g *dell);
int lg_fndr(del_g *dell);
int ntpop_ht(del_g *dell, char *buf, int invcnt);
int dfm(del_g *dell);


int rounde(char **);

list_t *at_thest(list_t **, const char *, int);
list_t *nde_tofin(list_t **, const char *, int);
size_t _prt_lgg(const list_t *);
int rm_incs(list_t **, unsigned int);
void rm_thelst(list_t **);

size_t sz_flst(const list_t *);
char **lg_chs(list_t *);
size_t _prt_lg(const list_t *);
list_t *beg_onl(list_t *, char *, char);
ssize_t fnd_thplc(list_t *, list_t *);



#endif
