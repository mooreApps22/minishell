
#ifndef TOKENS_H
# define TOKENS_H

# include "minishell.h"

typedef struct s_sort
{
	t_token	*a_now;
	t_token	*b_now;
	int		idx_a;
	int		idx_b;
}				t_sort;

bool	quoting(t_mini *m);
bool	tokenize_input(t_mini *m);
bool	redir(t_mini *m);
void	sort(t_mini *m);
bool	extract_tokens(t_mini *m, char *str, char *delims);

bool	join(t_mini *m);
bool	pipeline(t_mini *m);
void	type(t_mini *m);

#endif
