/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:01:40 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:01:42 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

/*
* @brief Print the current working directory
*/

void	builtin_pwd(t_data *data)
{
	ft_putendl_fd(data->pwd, STDOUT_FILENO);
}
