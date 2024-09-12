#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/include/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <termcap.h>
# include <curses.h>
# include <term.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct	s_data t_data;
typedef struct	s_cmd_tab t_cmd_tab;
typedef struct	s_simple_cmd t_simple_cmd;


typedef struct	s_data
{
	char	*input;
	char	*prompt;
}	t_data;

typedef struct	s_simple_cmd
{
	int		num_of_available_args;
	int		num_of_args;
	char	**args;
//	simple_command();
//	void	insert_arg(char *arg);	
}	t_simple_cmd;

typedef struct	s_cmd_tab
{
	int				num_of_available_simple_cmds;
	int				num_of_simple_cmds;
	t_simple_cmd	simple_cmds;
	char			*outfile;
	char			*infile;
	char			*errfile;
	int				background;
	
/*
	void			prompt();
	void			print();
	void			execute();
	void			clear();
	void			command();
	void			insert_simple_cmd();
*/
}	t_cmd_tab;


t_data	*init_data(void);
char	*get_prompt(void);
void	free_data(t_data *d);
void	executor(t_data *d);

// get path list
char	**get_paths(void); // get the PATH env
char	**split_cmd_opts(char *cmd_str); // split up cmd and opts
char	*find_cmd_path(char *cmd, char **path_list); // find exec path

#endif
