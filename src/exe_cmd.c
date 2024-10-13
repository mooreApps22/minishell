
#include "../inc/cmd.h"

char	**get_path(t_mini *m, char *cmd)
{
	char	*tmp;
	char	**ans;
	int		i;

	ans = ft_split(getenv("PATH"), ':');
	if (!ans)
		return (NULL);
	ft_lstlast(m->mem)->next = ft_lstnew(ans);
	i = 0;
	while (ans[i])
	{
		tmp = ans[i];
		ans[i] = ft_strjoin(tmp, "/");
		if (!ans)
			return (NULL);
		free(tmp);
		tmp = ans[i];
		ans[i] = ft_strjoin(tmp, cmd);
		if (!ans)
			return (NULL);
		ft_lstlast(m->mem)->next = ft_lstnew(ans[i]);
		free(tmp);
		i++;
	}
	return (ans);
}

static void	start_exe_rdr(t_mini *m, int idx)
{
	int		i;

	i = 0;
	while (i < m->cmd[idx].rdr_size)
	{
		if (m->cmd[idx].rdr[i].if_rdr)
		{
			if (dup2(m->cmd[idx].rdr[i].o_fd, m->cmd[idx].rdr[i].fd) == -1)
			{
				perror("minishell");
				exit(errno);
			}
		}
		else
			m->cmd[idx].if_exe = 0;
		i++;
	}
	m->exit_status = 0;
}

void	child_process(t_mini *m, int idx)
{
	sig_default(m);
	if (idx > 0)
		close(m->cmd[idx - 1].pipe[1]);
	if (idx != m->cmd_size - 1)
		close(m->cmd[idx].pipe[0]);
	if (idx != m->cmd_size - 1)
	{
		dup2(m->cmd[idx].pipe[1], STDOUT_FILENO);
		close(m->cmd[idx].pipe[1]);
	}
	if (idx != 0)
	{
		dup2(m->cmd[idx - 1].pipe[0], STDIN_FILENO);
		close(m->cmd[idx - 1].pipe[0]);
	}
	start_exe_rdr(m, idx);
	if (m->cmd[idx].hdc_size)
	{
		dup2(m->cmd[idx].hdc[m->cmd[idx].hdc_size - 1].pipe[0], STDIN_FILENO);
		close(m->cmd[idx].hdc[m->cmd[idx].hdc_size - 1].pipe[0]);
		close(m->cmd[idx].hdc[m->cmd[idx].hdc_size - 1].pipe[1]);
	}
	if (m->cmd[idx].if_exe)
		start_exe_cmd(m, idx);
	exit(1);
}

void	exe_parent(t_mini *m)
{
	start_exe_rdr(m, 0);
	if (m->cmd[0].hdc_size)
		dup2(m->cmd[0].hdc[m->cmd[0].hdc_size - 1].pipe[0], STDIN_FILENO);
	exe_builtin(m, 0, 1);
}

bool	exe_cmd(t_mini *m)
{
	int		i;

	i = -1;
	while (++i < m->cmd_size)
	{
		if (exe_pipe(m, i))
			return (1);
		if (m->cmd_size > 1 || !is_parent(m))
		{
			if (!m->cmd[i++].args)
				continue ;
			m->cmd[--i].pid = fork();
			if (m->cmd[i].pid == -1)
				return (1);
			if (m->cmd[i].pid == 0)
				child_process(m, i);
			if (i != m->cmd_size - 1)
				close(m->cmd[i].pipe[1]);
		}
		else
			exe_parent(m);
	}
	return (0);
}
