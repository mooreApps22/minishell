
#include "../inc/tokens.h"

static bool	check(t_mini *m)
{
	t_token	*now;

	now = m->t_head->next;
	while (now->next)
	{
		now = now->next;
	}
	if (now->type >= 0 && now->type <= 4)
		return (1);
	return (0);
}

static bool	new_tok(t_mini *m, char *cont, t_token *prev, t_token *now)
{
	t_token	*new_tok;

	new_tok = ft_malloc(sizeof(t_token), m->mem);
	if (!new_tok)
		return (1);
	new_tok->next = now->next;
	new_tok->cont = cont;
	new_tok->type = ARG;
	prev->next = new_tok;
	if (prev == m->t_tail)
		m->t_tail = new_tok;
	m->a_size++;
	return (0);
}

static bool	divide_tok_lp(t_mini *m, t_token **prev, t_token *now, char **tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		ft_lstadd_back(&m->mem, ft_lstnew(tmp[i]));
		if (new_tok(m, tmp[i], *prev, now))
			return (1);
		*prev = (*prev)->next;
		i++;
	}
	return (0);
}

static bool	divide_tok(t_mini *m, t_token *prev, t_token *now)
{
	char	**tmp;

	while (now)
	{
		if (ft_strchr(now->cont, ' ') && now->is_div)
		{
			tmp = ft_split(now->cont, ' ');
			if (!tmp)
				return (1);
			if (divide_tok_lp(m, &prev, now, tmp))
				return (1);
			now = prev->next;
			free(tmp);
		}
		else
		{
			prev = now;
			now = now->next;
		}
	}
	return (0);
}

bool	make_tokens(t_mini *m)
{
	sig_ignore();
	if (quoting(m))
		return (1);
	if (tokenize_input(m))
		return (1);
	sort(m);
	if (pipeline(m))
		return (1);
	sort(m);
	if (redir(m))
		return (1);
	sort(m);
	if (join(m))
		return (1);
	if (divide_tok(m, m->t_head, m->t_head->next))
		return (1);
	if (!m->t_head->next)
		return (1);
	type(m);
	if (check(m))
		return (1);
	return (0);
}
