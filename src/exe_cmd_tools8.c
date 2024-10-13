
#include "../inc/cmd.h"

void	b_cd_home(t_mini *m, int idx)
{
	if (chdir(getenv("HOME")) != 0)
		cd_error(m, idx);
	mod_env_cd(m, getenv("PWD"));
}
