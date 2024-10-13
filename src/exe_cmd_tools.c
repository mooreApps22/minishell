
#include "../inc/cmd.h"

static void	b_echo_n(t_cmd exe, int i)
{
	while (exe.args[i])
	{
		printf("%s", exe.args[i++]);
		if (exe.args[i])
			printf(" ");
	}
	exit(0);
}

bool	skip_option(t_cmd exe, int *idx)
{
	size_t	i;
	bool	flag;

	flag = false;
	while (exe.args[*idx])
	{
		if (exe.args[*idx][0] == '-' && exe.args[*idx][1])
		{
			i = 0;
			while (exe.args[*idx][++i])
			{
				if (exe.args[*idx][i] == 'n')
					flag = true;
				else
					break ;
			}
			if (i == ft_strlen(exe.args[*idx]) && exe.args[*idx][i] != '-')
				(*idx)++;
			else
				break ;
		}
		else
			break ;
	}
	return (flag);
}

void	b_echo(t_mini *m, int idx)
{
	int		i;
	bool	flag;

	i = 1;
	flag = skip_option(m->cmd[idx], &i);
	if (flag)
		b_echo_n(m->cmd[idx], i);
	else
	{
		while (m->cmd[idx].args[i])
		{
			printf("%s", m->cmd[idx].args[i++]);
			if (m->cmd[idx].args[i])
				printf(" ");
		}
		printf("\n");
	}
	exit(0);
}

void	b_pwd(t_mini *m, bool is_print)
{
	if (getcwd(m->path, PATH_MAX) != NULL)
	{
		if (is_print)
		{
			printf("%s\n", m->path);
			exit(0);
		}
	}
	else if (is_print == 1)
	{
		m->path = getenv("PWD");
		printf("%s\n", m->path);
		m->exit_status = 1;
		if (!is_parent(m))
			exit(1);
	}
	else
		m->path = getenv("PWD");
}

void	b_env(t_mini *m, int idx)
{
	int	i;

	if (m->cmd[idx].args[1])
	{
		ft_putstr_fd("minishell: we don't handle options or arguments.\n", 2);
		exit(1);
	}
	i = 0;
	while (__environ[i])
		printf("%s\n", __environ[i++]);
	exit(0);
}
