#include "../include/minishell.h"

//smoore@c2r6s6:~$

char	*get_prompt(void);

char	*get_prompt(void)
{
	char	*prompt;
	char	*temp;
	char	*user;
	char	*address;

	user = getenv("USER");
	address = getenv("SESSION_MANAGER");
	address = ft_substr(address, 6, 6);
	prompt = ft_strjoin(user, "@");
	temp = ft_strjoin(prompt, address);
	free(prompt);
	free(address);
	prompt = ft_strjoin(temp, ":~$");
	free(temp);
	return (prompt);
}
