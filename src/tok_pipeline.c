
#include "../inc/tokens.h"

static bool	new_tok(t_mini *m, int idx)
{
	t_token	*new_tok;

	new_tok = ft_malloc(sizeof(t_token), m->mem);
	if (!new_tok)
		return (1);
	new_tok->next = NULL;
	new_tok->cont = NULL;
	m->t_tail->next = new_tok;
	m->t_tail = new_tok;
	m->b_size++;
	new_tok->cont = ft_malloc(2, m->mem);
	if (!new_tok->cont)
		return (1);
	new_tok->cont[0] = '|';
	new_tok->cont[1] = '\0';
	new_tok->end_pos = -1;
	new_tok->pos = idx;
	new_tok->type = PIPE;
	new_tok->is_div = 0;
	return (0);
}

bool	pipeline(t_mini *m)
{
	int	i;

	i = 0;
	while (m->input[i])
	{
		if (m->input[i] == '|')
			if (new_tok(m, i))
				return (1);
		i++;
	}
	return (0);
}
