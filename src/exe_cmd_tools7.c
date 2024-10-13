
#include "../inc/cmd.h"

static void	mod_env_cd_oldpwd(t_mini *m, char *old_pwd)
{
	char	*tmp;

	tmp = ft_strjoin("OLDPWD=", old_pwd);
	if (!tmp)
	{
		perror("minishell: cd");
		if (m->job_size != 1)
			exit(errno);
	}
	m_export(m, tmp, "cd");
	free(tmp);
}

void	mod_env_cd_special(t_mini *m, char *old_pwd)
{
	char	*tmp;
	char	*new_pwd;

	mod_env_cd_oldpwd(m, old_pwd);
	b_pwd(m, 0);
	tmp = ft_strjoin("PWD=", m->path);
	if (!tmp)
	{
		perror("minishell: cd");
		if (m->job_size != 1)
			exit(errno);
	}
	new_pwd = ft_strjoin(tmp, "/.");
	if (!tmp)
	{
		free(tmp);
		perror("minishell: cd");
		if (m->job_size != 1)
			exit(errno);
	}
	m_export(m, new_pwd, "cd");
	free(new_pwd);
	free(tmp);
}

void	cd_error_special(t_mini *m)
{
	ft_putstr_fd("cd: error retrieving current directory: getcwd:", 2);
	ft_putstr_fd(" cannot access parent directories:", 2);
	ft_putstr_fd(" No such file or directory\n", 2);
	mod_env_cd_special(m, getenv("PWD"));
	if (m->job_size != 1)
		exit(1);
	m->exit_status = 1;
}

void	is_a_dir(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": is a directory\n", 2);
	exit(126);
}

void	check_if_dir(char *cmd)
{
	struct stat	statbuf;

	if (stat(cmd, &statbuf) != 0)
		return ;
	if (S_ISDIR(statbuf.st_mode))
		is_a_dir(cmd);
}
