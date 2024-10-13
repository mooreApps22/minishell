
#include "../inc/parse.h"

static int	ct_cmd_size(t_mini *m)
{
	int		ct;
	t_token	*now;

	ct = 1;
	now = m->t_head->next;
	while (now)
	{
		if (now->type == PIPE)
			ct++;
		now = now->next;
	}
	return (ct);
}

static bool	init_parse(t_mini *m)
{
	int	i;

	m->job_size = ct_cmd_size(m);
	m->cmd = ft_malloc(sizeof(t_cmd) * m->job_size, m->mem);
	if (!m->cmd)
		return (1);
	i = 0;
	while (i < m->job_size)
	{
		m->cmd[i].args = NULL;
		i++;
	}
	return (0);
}

bool	parser(t_mini *m)
{
	if (init_parse(m))
		return (1);
	if (parse_cmd(m))
		return (1);
	if (parse_redir(m))
		return (1);
	return (0);
}
