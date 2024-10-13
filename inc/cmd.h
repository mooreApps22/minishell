
#ifndef CMD_H
# define CMD_H

# include "minishell.h"

bool	exe_init(t_mini *m);
bool	exe_cmd(t_mini *m);
bool	exe_rdin(t_mini *m);
bool	exe_rdout(t_mini *m);
bool	exe_ap(t_mini *m);
void	exe_rdr(t_mini *m);
bool	exe_hdc(t_mini *m);
bool	exe_pipe(t_mini *m, int idx);
void	b_echo(t_mini *m, int idx);
void	b_cd(t_mini *m, int idx);
void	b_export(t_mini *m, int idx);
void	b_unset(t_mini *m, int idx);
void	b_env(t_mini *m, int idx);
void	b_exit(t_mini *m, int idx, bool is_print);
void	exe_builtin(t_mini *m, int idx, bool is_print);
void	start_exe_cmd(t_mini *m, int idx);
char	**get_path(t_mini *m, char *cmd);
void	cd_error_special(t_mini *m);
void	b_cd_handle(t_mini *m, int idx);
void	mod_env_cd(t_mini *m, char *old_pwd);
void	cd_error(t_mini *m, int idx);
void	mod_env_cd_special(t_mini *m, char *old_pwd);
void	b_cd_home(t_mini *m, int idx);
void	is_a_dir(char *str);
void	check_if_dir(char *cmd);

#endif
