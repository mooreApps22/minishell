/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_quotes2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:07:35 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:07:36 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

char		*complete_quoted_input(char *input);

static char	*check_and_complete_quotes(char *input)
{
	char	*new_input;
	int		i;
	int		delim;

	i = 0;
	while (input[i])
	{
		if (input[i] != '\'' && input[i] != '\"')
		{
			i++;
			continue ;
		}
		delim = input[i];
		i++;
		while (input[i] && input[i] != delim)
			i++;
		if (!input[i])
		{
			new_input = finish_quotes(input);
			return (free(input), new_input);
		}
		else
			i++;
	}
	return (input);
}

char	*complete_quoted_input(char *input)
{
	char	*new_input;

	new_input = NULL;
	if (!has_quotes(input))
		return (input);
	while (!has_finished_quotes(input))
	{
		new_input = check_and_complete_quotes(input);
		if (new_input == input)
			break ;
		input = new_input;
	}
	return (input);
}
