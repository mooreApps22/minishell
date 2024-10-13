
#include "../inc/cmd.h"

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
