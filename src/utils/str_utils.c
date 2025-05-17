/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:08:10 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:08:11 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

bool	word_match(char *word, char *check);
bool	is_blank(char c);
bool	is_symbol(char c);
bool	is_quote(char c);
bool	is_ascii_symbol(char c);

bool	word_match(char *word, char *check)
{
	if (ft_strcmp(word, check) == 0)
		return (true);
	return (false);
}

bool	is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

bool	is_symbol(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

bool	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

bool	is_ascii_symbol(char c)
{
	return (ft_isascii(c) && !ft_isalnum(c));
}
