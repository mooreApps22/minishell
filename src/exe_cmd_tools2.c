
#include "../inc/cmd.h"

void	mod_env_cd(t_mini *m, char *old_pwd)
{
	char	*tmp;

	tmp = ft_strjoin("OLDPWD=", old_pwd);
	if (!tmp)
	{
		perror("minishell: cd");
		if (m->cmd_size != 1)
			exit(errno);
	}
	m_export(m, tmp, "cd");
	free(tmp);
	b_pwd(m, 0);
	tmp = ft_strjoin("PWD=", m->path);
	if (!tmp)
	{
		perror("minishell: cd");
		if (m->cmd_size != 1)
			exit(errno);
	}
	m_export(m, tmp, "cd");
	free(tmp);
}

void	cd_error(t_mini *m, int idx)
{
	ft_putstr_fd("minishell: cd: ", 2);
	if (errno == EFAULT && !ft_strncmp(m->cmd[idx].args[1], "-", 2))
		ft_putstr_fd("OLDPWD not set\n", 2);
	else
		perror(m->cmd[idx].args[1]);
	if (m->cmd_size != 1)
		exit(1);
	m->exit_status = 1;
}

void	b_cd(t_mini *m, int idx)
{
	if (!m->cmd[idx].args[1])
		b_cd_home(m, idx);
	else if (ft_strncmp(m->cmd[idx].args[1], "~", 2) == 0
		|| !m->cmd[idx].args[1]
		|| ft_strncmp(m->cmd[idx].args[1], "~/", 3) == 0)
		b_cd_home(m, idx);
	else if (ft_strncmp(m->cmd[idx].args[1], "-", 2) == 0
		|| ft_strncmp(m->cmd[idx].args[1], "-/", 3) == 0)
	{
		if (chdir(getenv("OLDPWD")) != 0)
			cd_error(m, idx);
		else
			printf("%s\n", getenv("OLDPWD"));
		mod_env_cd(m, getenv("PWD"));
	}
	else
		b_cd_handle(m, idx);
	if (m->cmd_size != 1)
		exit(0);
}

static void	b_export_error(t_mini *m, char *str)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	m->exit_status = 1;
}

void	b_export(t_mini *m, int idx)
{
	int	i;
	int	j;

	i = 0;
	while (m->cmd[idx].args[++i])
	{
		j = 0;
		while (m->cmd[idx].args[i][j])
		{
			if (m->cmd[idx].args[i][j] == '=' && j != 0)
			{
				m_export(m, m->cmd[idx].args[i], "export");
				break ;
			}
			if (!ft_isalpha(m->cmd[idx].args[i][0])
				|| !ft_isalnum(m->cmd[idx].args[i][j]))
			{
				b_export_error(m, m->cmd[idx].args[i]);
				break ;
			}
			j++;
		}
	}
	if (m->cmd_size != 1)
		exit(0);
}
