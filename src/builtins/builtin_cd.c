/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:59:50 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 14:59:51 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/data.h"

void	builtin_cd(t_data *data, t_cmd *cmd)
{
	if (cmd->cmdv[1])
	{
		if (chdir(cmd->cmdv[1]) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(getenv("HOME")) != 0)
			perror("cd");
	}
	free(data->pwd);
	data->pwd = getcwd(NULL, 0);
}
