/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:51:02 by ilouacha          #+#    #+#             */
/*   Updated: 2023/05/23 11:49:37 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	malloc_line(t_list *stash, char **line)
{
	int		len;
	int		i;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i] && stash->content[i] != '\n')
		{
			i++;
			len++;
		}
		stash = stash->next;
	}
	if (stash->content[i] && stash->content[i] == '\n')
		len ++;
	(*line) = malloc(sizeof(char) * (len + 1));
}

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*cleaned_stash;
	int		i;
	int		j;

	cleaned_stash = malloc(sizeof(t_list));
	last = get_last_elt(*stash);
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		
	cleaned_stash->content = malloc(sizeof(char) * ft_strlen());
	last = *stash;
	while (current)
	{
		i = 0;
		while (current->content[i] && current->content[i] != '\n')
		{
			
			cleaned_stash(current->next);
		}
		current = current->next;
	}
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

void	extract_line(t_list *stash, char **line)
{
	t_list	*current;
	int		i;
	int		j;

	if (stash == NULL)
		return ;
	malloc_line(stash, line);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j++] = '\0';
}

size_t	ft_strlen(char *str)
{
	int	len;

	while (*str++)
	{
		len++;
	}
	return (len);
}
