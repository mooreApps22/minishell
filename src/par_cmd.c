
#include "../inc/parse.h"

static int	get_arg_size(t_token *now)
{
	int	ct;

	ct = 1;
	while (now)
	{
		if (now->type == PIPE)
			break ;
		if (now->type == COMMAND || now->type == ARG)
			if (now->cont)
				if (now->cont[0])
					ct++;
		now = now->next;
	}
	return (ct);
}

static void	fill_args(t_mini *m, int idx, int arg_size, t_token *now)
{
	int		i;

	i = 0;
	while (i < arg_size - 1)
	{
		if (now->type == COMMAND || now->type == ARG)
			if (now->cont)
				if (now->cont[0])
					m->cmd[idx].args[i++] = now->cont;
		now = now->next;
	}
	m->cmd[idx].args[i] = NULL;
	m->cmd[idx].if_executable = 1;
}

bool	parse_cmd(t_mini *m)
{
	int		i;
	int		arg_size;
	t_token	*now;

	now = m->t_head->next;
	i = 0;
	while (i < m->job_size && now)
	{
		arg_size = get_arg_size(now);
		if (arg_size != 1)
		{
			m->cmd[i].args = ft_malloc(arg_size * sizeof(char *), m->mem);
			if (!m->cmd[i].args)
				return (1);
			fill_args(m, i, arg_size, now);
		}
		now = next_pipe(now);
		i++;
	}
	return (0);
}
