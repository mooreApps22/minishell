#include "../include/minishell.h"

int	main(void)
{
	t_data	*d;
	
	d = init_data();
	while (true)
	{
		d->input = readline(d->prompt);
		if (d->input)
		{
			//executor(d);
			free(d->input);
		}

	}
	free_data(d);
	return (0);
}
