
#include "../inc/minishell.h"

void	read_again(int signum)
{
	g_sig = signum;
	rl_on_new_line();
	rl_replace_line("", 0);
	printf("\n");
	rl_redisplay();
}

void	sig_int_hdc(int signum)
{
	g_sig = signum;
	printf("\n");
	exit(130);
}
