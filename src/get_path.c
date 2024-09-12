#include "include/minishell.h"

char	**get_paths(void);
char	**split_cmd_opts(char *cmd_str);
char	*find_cmd_path(char *cmd, char **path_list);

char	**get_paths(void)
{
	char	**path_list;
	char	*path_env;

	path_env = getenv("PATH");
	path_list = ft_split(path_env, ':');
	if (!path_list)
		return (NULL);
	return (path_list);
}

char	**split_cmd_opts(char *cmd_str)
{
	char **cmd_opts;

	cmd_opts = ft_split(cmd_str, ' ');
	if (!cmd_opts)
		return (NULL);
	return (cmd_opts);
}

char	*find_cmd_path(char *cmd, char **path_list)
{
	char	*tmp;
	char	*cmd_path;

	while (**path_list)
	{
		tmp = ft_strjoin(*path_list, "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		path_list++;
	}
	return (NULL);
}
