#include "../include/minishell.h"

t_data	*init_data(void);


t_data	*init_data(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (NULL);
	d->prompt = get_prompt();
	return (d);
}
