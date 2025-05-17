/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:00:45 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:01:00 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

void	builtin_env(t_data *data);

void	builtin_env(t_data *data)
{
	char	**tmp;

	tmp = data->env;
	signal(SIGPIPE, SIG_IGN);
	while (*tmp)
	{
		ft_putendl_fd(*tmp, STDOUT_FILENO);
		tmp++;
	}
	signal(SIGPIPE, SIG_DFL);
}
