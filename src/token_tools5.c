
#include "../inc/tokenizer.h"

static bool	join_do(t_mini *m, t_token *now)
{
	char	*ctmp;
	t_token	*ttmp;

	ttmp = now->next;
	ctmp = now->cont;
	now->cont = ft_strjoin(ctmp, ttmp->cont);
	ft_lstadd_back(&m->mem, ft_lstnew(now->cont));
	if (!now->cont)
		return (1);
	ft_free(ctmp, m->mem);
	ft_free(ttmp->cont, m->mem);
	now->end_pos = ttmp->end_pos;
	now->next = ttmp->next;
	ft_free(ttmp, m->mem);
	return (0);
}

bool	join(t_mini *m)
{
	t_token	*now;

	now = m->t_head;
	while (now->next)
	{
		if (now->end_pos + 1 == now->next->pos && now->next->end_pos != -1)
		{
			if (join_do(m, now))
				return (1);
		}
		else
			now = now->next;
	}
	m->t_tail = now;
	return (0);
}
