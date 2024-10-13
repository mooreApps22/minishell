
#include "../inc/cmd.h"

static void	handle_sigexit(int *status)
{
	if (WTERMSIG(*status) != SIGPIPE)
		*status = WTERMSIG(*status) + 128;
	else
		*status = 0;
}

void	end_exe(t_mini *m, int *status)
{
	int	i;

	i = 0;
	while (i < m->cmd_size)
	{
		if (m->cmd[i].args)
			wait(status);
		else
		{
			*status = 0;
			break ;
		}
		if (WIFEXITED(*status))
			*status = WEXITSTATUS(*status);
		else if (WIFSIGNALED(*status))
			handle_sigexit(status);
		if (*status == 130 && m->is_print_sig)
			printf("^C\n");
		else if (*status == 131 && m->is_print_sig)
			printf("^\\Quit: 3\n");
		if (*status == 130 || *status == 131)
			m->is_print_sig = 0;
		i++;
	}
}

bool	exe(t_mini *m)
{
	int	status;
	int	i;

	if (exe_hdc(m))
		return (1);
	exe_rdr(m);
	if (exe_cmd(m))
		return (1);
	i = 0;
	while (i < m->cmd_size - 1)
	{
		close(m->cmd[i].pipe[0]);
		close(m->cmd[i++].pipe[1]);
	}
	if (!is_parent(m) || m->cmd_size != 1)
	{
		end_exe(m, &status);
		m->exit_status = status;
	}
	return (0);
}
