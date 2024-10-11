
#include "../inc/minishell.h"

int	g_sig;

void	sig_block(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_init(void)
{
	signal(SIGINT, read_again);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_default(t_mini *m)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &m->term_orig);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
