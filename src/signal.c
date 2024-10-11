
#include "../inc/minishell.h"

volatile sig_atomic_t	g_signal;

void	sig_block(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_default(t_mini *m)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &m->terminal);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	read_again(int signum)
{
	g_signal = signum;
	rl_on_new_line();
	rl_replace_line("", 0);
	printf("\n");
	rl_redisplay();
}

void	sig_int_hdc(int signum)
{
	g_signal = signum;
	printf("\n");
	exit(130);
}

void	init_signal(void)
{
	signal(SIGINT, read_again);
	signal(SIGQUIT, SIG_IGN);
}
