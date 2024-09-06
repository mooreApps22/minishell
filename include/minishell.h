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
typedef struct	s_cmd t_cmd;


typedef struct	s_data
{
	char	*input;
}	t_data;


t_data	*init_data(void);
char	*get_prompt(void);

#endif
