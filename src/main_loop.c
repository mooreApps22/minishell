
#include "../inc/minishell.h"

void	restart_lp(t_mini *m)
{
	ft_free_all(m->mem);
	free(m->mem);
	free(m->input);
	shell_init(m);
	init_signal();
}

static void	main_loop_process(t_mini *m)
{
	if (tokenize(m))
	{
		if (m->t_head->next)
		{
			if (m->t_tail->type == REDIR_IN)
				ft_putstr_fd(
					"minishell: syntax error near unexpected token `<'\n", 2);
			else
				ft_putstr_fd(
					"minishell:\
syntax error near unexpected token `newline'\n", 2);
		}
		restart_lp(m);
		return ;
	}
	if (parse(m))
	{
		ft_putstr_fd(
			"minishell: parsing error\n", 2);
		restart_lp(m);
		return ;
	}
	if (exe(m))
		m->exit_status = 1;
	restart_lp(m);
}

void	main_loop(t_mini *m)
{
	while (1)
	{
		config_terminal(m);
		m->input = readline(PROMPT);
		if (!m->input)
		{
			printf("exit\n");
			break ;
		}
		if (m->input[0] == '\0')
		{
			restart_lp(m);
			continue ;
		}
		add_history(m->input);
		if (g_signal == SIGINT)
		{
			m->exit_status = 1;
			g_signal = 0;
		}
		main_loop_process(m);
	}
}
