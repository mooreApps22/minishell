
#include "../inc/cmd.h"

void	reset_env(t_mini *m, char **new_env, int tar_idx)
{
	int	i;

	i = -1;
	while (++i != tar_idx)
		new_env[i] = __environ[i];
	while (__environ[i + 1])
	{
		new_env[i] = __environ[i + 1];
		i++;
	}
	new_env[i] = NULL;
	ft_free(__environ[tar_idx], m->mem_env);
	__environ = new_env;
}

bool	env_size_dec(t_mini *m, char *target, int tar_len)
{
	char	**new_env;
	int		i;
	int		tar_idx;

	tar_idx = -1;
	i = 0;
	while (__environ[i])
	{
		if (ft_strncmp(__environ[i], target, tar_len) == 0)
			if (__environ[i][tar_len] == '=')
				tar_idx = i;
		i++;
	}
	new_env = ft_malloc(sizeof(char *) * i, m->mem_env);
	if (!new_env)
		return (1);
	if (tar_idx != -1)
		reset_env(m, new_env, tar_idx);
	else
		return (1);
	return (0);
}

void	m_unset(t_mini *m, char *target)
{
	if (env_size_dec(m, target, ft_strlen(target)))
	{
		if (errno == ENOMEM)
		{
			perror("minishell: unset:");
			m->exit_status = errno;
			if (m->cmd_size != 1)
				exit(errno);
		}
	}
}

void	exe_builtin(t_mini *m, int idx, bool is_print)
{
	if (!ft_strncmp(m->cmd[idx].args[0], "echo", 5))
		b_echo(m, idx);
	if (!ft_strncmp(m->cmd[idx].args[0], "cd", 3))
		b_cd(m, idx);
	if (!ft_strncmp(m->cmd[idx].args[0], "pwd", 4))
		b_pwd(m, 1);
	if (!ft_strncmp(m->cmd[idx].args[0], "export", 7))
		b_export(m, idx);
	if (!ft_strncmp(m->cmd[idx].args[0], "unset", 6))
		b_unset(m, idx);
	if (!ft_strncmp(m->cmd[idx].args[0], "env", 4))
		b_env(m, idx);
	if (!ft_strncmp(m->cmd[idx].args[0], "exit", 5))
		b_exit(m, idx, is_print);
}

void	b_cd_handle(t_mini *m, int idx)
{
	int	flag;
	int	cmp;

	flag = chdir(m->cmd[idx].args[1]);
	cmp = ft_strncmp(m->cmd[idx].args[1], ".", 2);
	if (flag == -1)
		cd_error(m, idx);
	else if (!cmp)
	{
		if (access(getenv("PWD"), F_OK) != 0)
			cd_error_special(m);
		else
			mod_env_cd(m, getenv("PWD"));
	}
	else
		mod_env_cd(m, getenv("PWD"));
}
