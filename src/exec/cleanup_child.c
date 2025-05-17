/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:02:42 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:02:44 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

void	cleanup_child(t_data *data, int exit_status);

void	cleanup_child(t_data *data, int exit_status)
{
	if (data)
	{
		free_minishell(data);
		ft_str_arr_free(&data->env);
		if (data->pwd)
			free(data->pwd);
		free(data);
	}
	exit(exit_status);
}
