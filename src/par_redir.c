
#include "../inc/parse.h"

static void	get_size(t_mini *m, int idx, t_token *now)
{
	int		ct;
	t_token	*tmp;

	tmp = now;
	ct = 0;
	while (now)
	{
		if (now->type == PIPE)
			break ;
		if (now->type >= 1 && now->type <= 3)
			ct++;
		now = now->next;
	}
	m->cmd[idx].rdr_ct = ct;
	ct = 0;
	now = tmp;
	while (now)
	{
		if (now->type == PIPE)
			break ;
		if (now->type == HEREDOC)
			ct++;
		now = now->next;
	}
	m->cmd[idx].hdc_size = ct;
}

static void	fill_hdc(t_mini *m, int idx, t_token *now)
{
	int	i;

	i = 0;
	while (i < m->cmd[idx].hdc_size)
	{
		if (now->type == FD)
		{
			if (now->next->type == HEREDOC)
			{
				m->cmd[idx].hdc[i].fd = ft_atoi(now->cont);
				now = now->next->next;
				m->cmd[idx].hdc[i++].eof = now->cont;
				i++;
			}
		}
		else if (now->type == HEREDOC)
		{
			m->cmd[idx].hdc[i].fd = 0;
			now = now->next;
			m->cmd[idx].hdc[i++].eof = now->cont;
		}
		now = now->next;
	}
}

static void	fill_rdr(t_mini *m, int idx, t_token *now)
{
	int	i;

	i = 0;
	while (i < m->cmd[idx].rdr_ct)
	{
		if (now->type == FD)
		{
			if (now->next->type != HEREDOC)
			{
				fill_rdr_fd(&(m->cmd[idx]), i++, now, now->next->next);
				now = now->next->next;
			}
		}
		else if (now->type >= 1 && now->type <= 3)
		{
			fill_rdr_nfd(&(m->cmd[idx]), i++, now, now->next);
			now = now->next;
		}
		now = now->next;
	}
}

bool	parse_redir(t_mini *m)
{
	int		i;
	t_token	*now;

	now = m->t_head->next;
	i = 0;
	while (i < m->job_size && now)
	{
		get_size(m, i, now);
		if (rdr_malloc(m, i))
			return (1);
		fill_rdr(m, i, now);
		fill_hdc(m, i, now);
		i++;
		now = next_pipe(now);
	}
	return (0);
}
