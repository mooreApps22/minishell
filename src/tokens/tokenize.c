/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:07:02 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:07:05 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

void	tokenize(t_data *data);

void	tokenize(t_data *data)
{
	char	**words;
	char	**cur;
	t_token	*new;

	if (!g_signal && data->input)
	{
		words = command_line_split(data->input);
		cur = words;
		while (*cur)
		{
			new = tok_lstnew(*cur);
			if (!new)
				return (tok_lstclear(&data->toks), ft_str_arr_free(&words));
			tok_lstadd_back(&data->toks, new);
			cur++;
		}
	}
	ft_str_arr_free(&words);
	assign_tok_types(data->toks, data);
}
