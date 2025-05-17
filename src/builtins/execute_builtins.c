/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:02:06 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:02:08 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

void	execute_builtin(t_data *data, char *cmd);

void	execute_builtin(t_data *data, char *cmd)
{
	if (word_match(cmd, "cd"))
		builtin_cd(data, data->cmds);
	else if (word_match(cmd, "echo"))
		builtin_echo(data->cmds);
	else if (word_match(cmd, "env"))
		builtin_env(data);
	else if (word_match(cmd, "export"))
		builtin_export(data, data->cmds->cmdv);
	else if (word_match(cmd, "exit"))
		builtin_exit(data);
	else if (word_match(cmd, "pwd"))
		builtin_pwd(data);
	else if (word_match(cmd, "unset"))
		builtin_unset(data, data->cmds->cmdv);
}
