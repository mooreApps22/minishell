
#include "../inc/cmd.h"

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
