
#ifndef ENV_H
# define ENV_H
# include "minishell.h"

typedef struct s_env
{
	char	*cont;
	int		*idx;
	int		num;
}				t_env;

char	*get_name(t_mini *m, t_env *env, char *str, int idx);
bool	copy_env(t_mini *m, t_env *env, char *env_cont);
char	*get_cont(t_mini *m, char *name);
#endif
