#include "../include/minishell.h"

char	*get_prompt(void);

char	*get_prompt(void)
{
	char	*user;

	user = getenv("USER");
	if (!user)
		printf("User not found\n");
	user = ft_strjoin(user, "@");
	return(user);
}
