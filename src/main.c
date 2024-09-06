#include "../include/minishell.h"

int	main(void)
{
	t_data	*d;
	char	*user;
	
	user = get_prompt();
	d = init_data();
	printf("%s\n", user);
	return (0);
}
