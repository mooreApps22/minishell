/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir_file_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:06:28 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:06:29 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"

bool	check_redir_file_error(t_token *symbol, t_token *file)
{
	if (symbol->type == RE_READ && file->type != FN_READ)
		return (true);
	else if (symbol->type == RE_TRUNC && file->type != FN_TRUNC)
		return (true);
	else if (symbol->type == RE_APPEND && file->type != FN_APPEND)
		return (true);
	else if (symbol->type == RE_HEREDOC && file->type != DELIM)
		return (true);
	else
		return (false);
}
