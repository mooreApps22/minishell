/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:07:27 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:07:28 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

static bool	finish_quotes_util(char **join, char **buf, char **str1,
				char quote);
char		*finish_quotes(char *input);

static bool	finish_quotes_util(char **join, char **buf, char **str1,
	char quote)
{
	*str1 = ft_strdup(*join);
	free(*join);
	ft_putstr_fd("> ", STDOUT_FILENO);
	*buf = get_next_line(STDIN_FILENO);
	if (g_signal == SIGINT || !*buf)
	{
		free(*str1);
		return (false);
	}
	*join = ft_strjoin(*str1, *buf);
	free(*str1);
	if (ft_strchr(*buf, quote))
		return (true);
	free(*buf);
	return (false);
}

char	*finish_quotes(char *input)
{
	char	quote;
	char	*buf;
	char	*str1;
	char	*join;
	bool	found;

	found = false;
	quote = get_first_quote(input);
	join = ft_strjoin(input, "\n");
	buf = NULL;
	str1 = NULL;
	if (quote == 'x')
	{
		free(join);
		return (NULL);
	}
	while (!found)
	{
		found = finish_quotes_util(&join, &buf, &str1, quote);
		if (g_signal == SIGINT || !buf)
			return (NULL);
	}
	if (buf)
		free(buf);
	return (join);
}
