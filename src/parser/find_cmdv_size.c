/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmdv_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:04:11 by smoore            #+#    #+#             */
/*   Updated: 2025/05/17 15:04:13 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

int		find_cmdv_size(t_token *toks);
char	**get_cmdv(t_token *toks, int size);

int	find_cmdv_size(t_token *toks)
{
	t_token	*cur;
	int		size;

	size = 0;
	cur = toks;
	while (cur && cur->type != PIPE)
	{
		if (cur->type == CMD || cur->type == ARG)
			size++;
		cur = cur->next;
	}
	return (size);
}

char	**get_cmdv(t_token *toks, int size)
{
	char	**cmdv;
	t_token	*cur;
	int		i;

	i = 0;
	if (!toks)
		return (NULL);
	cmdv = malloc(sizeof(char *) * (size + 1));
	if (!cmdv)
		return (NULL);
	cur = toks;
	while (cur && cur->type != PIPE)
	{
		if ((cur->type == CMD || cur->type == ARG) && cur->type != PIPE)
			cmdv[i++] = ft_strdup(cur->str);
		cur = cur->next;
	}
	cmdv[i] = NULL;
	return (cmdv);
}
