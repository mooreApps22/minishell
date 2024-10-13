
#include "../inc/cmd.h"

void	b_pwd(t_mini *m, bool is_print)
{
	if (getcwd(m->path, PATH_MAX) != NULL)
	{
		if (is_print)
		{
			printf("%s\n", m->path);
			exit(0);
		}
	}
	else if (is_print == 1)
	{
		m->path = getenv("PWD");
		printf("%s\n", m->path);
		m->exit_status = 1;
		if (!is_parent(m))
			exit(1);
	}
	else
		m->path = getenv("PWD");
}
