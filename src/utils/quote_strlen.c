/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:08:00 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:08:02 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

static void	handle_double_quote(char *str, int *i);
static void	handle_single_quote(char *str, int *i);
static void	quoted_strlen_util(char *str, int *i);
int			quoted_strlen(char *str);

static void	handle_single_quote(char *str, int *i)
{
	(*i)++;
	while (str[*i] && str[*i] != '\'')
	{
		if (str[*i] == '\"')
		{
			(*i)++;
			while (str[*i] && str[*i] != '\"')
				(*i)++;
			if (str[*i] == '\"')
				(*i)++;
		}
		else
			(*i)++;
	}
	if (str[*i] == '\'')
		(*i)++;
}

static void	handle_double_quote(char *str, int *i)
{
	(*i)++;
	while (str[*i] && str[*i] != '\"')
	{
		if (str[*i] == '\'')
		{
			(*i)++;
			while (str[*i] && str[*i] != '\'')
				(*i)++;
			if (str[*i] == '\'')
				(*i)++;
		}
		else
			(*i)++;
	}
	if (str[*i] == '\"')
		(*i)++;
}

static void	quoted_strlen_util(char *str, int *i)
{
	if (str[*i] == '\'')
		handle_single_quote(str, i);
	else if (str[*i] == '\"')
		handle_double_quote(str, i);
	else
	{
		while (str[*i] && !is_blank(str[*i]) && !is_quote(str[*i])
			&& !is_symbol(str[*i]))
			(*i)++;
	}
}

int	quoted_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !is_blank(str[i]) && !is_symbol(str[i]))
		quoted_strlen_util(str, &i);
	return (i);
}
