
#include "../inc/parser.h"

t_token	*next_pipe(t_token *now)
{
	while (now)
	{
		if (now->type == PIPE)
			break ;
		now = now->next;
	}
	if (now)
		return (now->next);
	else
		return (NULL);
}

bool	rdr_malloc(t_mini *m, int idx)
{
	if (m->exe[idx].rdr_size != 0)
	{
		m->exe[idx].rdr = ft_malloc(m->exe[idx].rdr_size * sizeof(t_rdr),
				m->mem);
		if (!m->exe[idx].rdr)
			return (1);
	}
	if (m->exe[idx].hdc_size != 0)
	{
		m->exe[idx].hdc = ft_malloc(m->exe[idx].hdc_size * sizeof(t_hdc),
				m->mem);
		if (!m->exe[idx].hdc)
			return (1);
	}
	return (0);
}

void	fill_rdr_nfd(t_exe *exe, int idx, t_token *type, t_token *fn)
{
	if (type->type == APPEND || type->type == REDIR_OUT)
		exe->rdr[idx].fd = 1;
	if (type->type == REDIR_IN)
		exe->rdr[idx].fd = 0;
	exe->rdr[idx].type = type->type;
	exe->rdr[idx].fn = fn->cont;
}

void	fill_rdr_fd(t_exe *exe, int idx, t_token *fd, t_token *fn)
{
	exe->rdr[idx].fd = ft_atoi(fd->cont);
	exe->rdr[idx].type = fd->next->type;
	exe->rdr[idx].fn = fn->cont;
}
