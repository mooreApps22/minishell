/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:05:19 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:05:20 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

bool	is_builtin_cmd_child(char *cmdv)
{
	const char	*builtins[] = {
		"cd", "echo", "env", "exit", "export", "pwd", "unset"
	};
	int			i;

	if (!cmdv)
		return (NULL);
	i = 0;
	while (i < 7)
	{
		if (word_match(cmdv, (char *)builtins[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	is_builtin_cmd_parent(char *cmdv)
{
	const char	*builtins[] = {
		"cd", "exit", "export", "unset"
	};
	int			i;

	if (!cmdv)
		return (NULL);
	i = 0;
	while (i <= 3)
	{
		if (word_match(cmdv, (char *)builtins[i]))
			return (true);
		i++;
	}
	return (false);
}
