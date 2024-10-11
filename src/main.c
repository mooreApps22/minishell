
#include "../inc/minishell.h"

static void	handle_shell_lv(t_mini *m)
{
	char	*tmp;
	int		lv;
	char	*lv_tmp;

	lv = ft_atoi(getenv("SHLVL")) + 1;
	lv_tmp = ft_itoa(lv);
	tmp = ft_strjoin("SHLVL=", lv_tmp);
	if (!tmp)
	{
		perror("minishell: cd");
		exit(1);
	}
	free(lv_tmp);
	m_export(m, tmp, NULL);
	ft_lstlast(m->mem_env)->next = ft_lstnew(tmp);
}

static void	start_env(t_mini *m)
{
	char	*tmp;

	m_unset(m, "OLDPWD");
	b_pwd(m, 0);
	tmp = ft_strjoin("PWD=", m->path);
	if (!tmp)
	{
		perror("minishell: cd");
		exit(1);
	}
	m_export(m, tmp, NULL);
	ft_lstlast(m->mem_env)->next = ft_lstnew(tmp);
	handle_shell_lv(m);
}

void	config_terminal(t_mini *m)
{
	struct termios	termios;

	ft_memset(&m->terminal, 0, sizeof(m->terminal));
	tcgetattr(STDIN_FILENO, &m->terminal);
	termios = m->terminal;
	termios.c_lflag &= ~ECHOCTL;
	termios.c_lflag |= (ECHO | ICANON | ISIG);
	tcsetattr(STDIN_FILENO, TCSANOW, &termios);
}

int	main(void)
{
	t_mini	m;

	init_signal();
	config_terminal(&m);
	m.end_stat = 0;
	m.mem_env = ft_lstnew(NULL);
	if (!m.mem_env)
	{
		perror("minishell");
		exit(1);
	}
	shell_init(&m);
	if (env_init(&m))
	{
		perror("minishell");
		exit(1);
	}
	start_env(&m);
	main_loop(&m);
	ft_free_all(m.mem_env);
	exit(0);
}
