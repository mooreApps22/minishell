
#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

typedef struct s_sort
{
	t_token	*a_now;
	t_token	*b_now;
	int		idx_a;
	int		idx_b;
}				t_sort;

bool	quote(t_mini *m);
bool	normal(t_mini *m);
bool	redir(t_mini *m);
void	sort(t_mini *m);
bool	minishell_strtok(t_mini *m, char *str, char *charset);
bool	join(t_mini *m);
bool	pipeline(t_mini *m);
void	type(t_mini *m);

#endif
