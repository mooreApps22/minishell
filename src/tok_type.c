
#include "../inc/tokens.h"

static void	type_cmd_dlt_fn(t_token *now, t_token *prev)
{
	if (prev->type == PIPE || prev->type == FILENAME)
		now->type = COMMAND;
	else if (prev->type == DELIMETER)
		now->type = COMMAND;
	else if (prev->type == HEREDOC)
		now->type = DELIMETER;
	else if (prev->type == APPEND
		|| prev->type == REDIR_IN || prev->type == REDIR_OUT)
		now->type = FILENAME;
	else
		now->type = ARG;
}

//change prev type
static bool	type_fd(t_token *prev, int pos)
{
	if (ft_strlen(prev->cont) != 1)
		return (0);
	if (!ft_isdigit(prev->cont[0]))
		return (0);
	if (prev->end_pos + 1 != pos)
		return (0);
	prev->type = FD;
	return (1);
}

static void	type_init(t_mini *m, t_token **now, t_token **prev)
{
	(*now) = m->t_head->next;
	if (!(*now))
		return ;
	if ((*now)->next)
	{
		if ((*now)->next->type == REDIR_OUT
			|| (*now)->next->type == APPEND)
		{
			if (!type_fd((*now), (*now)->next->pos))
				(*now)->type = COMMAND;
		}
		else if ((*now)->end_pos != -1)
			(*now)->type = COMMAND;
	}
	else if ((*now)->end_pos != -1)
		(*now)->type = COMMAND;
	*prev = *now;
	(*now) = (*now)->next;
}

void	type(t_mini *m)
{
	t_token	*now;
	t_token	*prev;

	type_init(m, &now, &prev);
	while (now)
	{
		if (prev->type != COMMAND && now->end_pos != -1)
			type_cmd_dlt_fn(now, prev);
		else if ((prev->type == ARG || prev->type == COMMAND)
			&& (now->type >= 1 && now->type <= 4))
			type_fd(prev, now->pos);
		else if (now->end_pos != -1)
			now->type = ARG;
		prev = now;
		now = now->next;
	}
}
