/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:06:37 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:06:38 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

int		count_words(char *line);
char	**allocate_words_memory(char *line);

int	count_words(char *line)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (line[i])
	{
		while (is_blank(line[i]))
			i++;
		if (is_symbol(line[i]))
		{
			size++;
			i++;
			if (line[i] == line[i - 1] && line[i] != '|')
				i++;
		}
		else if (line[i])
		{
			size++;
			i += quoted_strlen(&line[i]);
		}
	}
	return (size);
}

char	**allocate_words_memory(char *line)
{
	char	**words;
	int		size;

	size = count_words(line);
	words = malloc(sizeof(char *) * (size + 1));
	if (!words)
		return (NULL);
	words[size] = NULL;
	return (words);
}
