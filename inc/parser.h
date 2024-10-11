
#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"

bool	parse_redir(t_mini *m);
bool	parse_fd(t_mini *m);
bool	parse_cmd(t_mini *m);
t_token	*next_pipe(t_token *now);
bool	rdr_malloc(t_mini *m, int idx);
void	fill_rdr_nfd(t_exe *exe, int idx, t_token *type, t_token *fn);
void	fill_rdr_fd(t_exe *exe, int idx, t_token *fd, t_token *fn);
#endif
