
#include "../inc/parse.h"

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
	if (m->cmd[idx].rdr_size != 0)
	{
		m->cmd[idx].rdr = ft_malloc(m->cmd[idx].rdr_size * sizeof(t_rdr),
				m->mem);
		if (!m->cmd[idx].rdr)
			return (1);
	}
	if (m->cmd[idx].hdc_size != 0)
	{
		m->cmd[idx].hdc = ft_malloc(m->cmd[idx].hdc_size * sizeof(t_hdc),
				m->mem);
		if (!m->cmd[idx].hdc)
			return (1);
	}
	return (0);
}

void	fill_rdr_nfd(t_cmd *cmd, int idx, t_token *type, t_token *fn)
{
	if (type->type == APPEND || type->type == REDIR_OUT)
		cmd->rdr[idx].fd = 1;
	if (type->type == REDIR_IN)
		cmd->rdr[idx].fd = 0;
	cmd->rdr[idx].type = type->type;
	cmd->rdr[idx].fn = fn->cont;
}

void	fill_rdr_fd(t_cmd *cmd, int idx, t_token *fd, t_token *fn)
{
	cmd->rdr[idx].fd = ft_atoi(fd->cont);
	cmd->rdr[idx].type = fd->next->type;
	cmd->rdr[idx].fn = fn->cont;
}
