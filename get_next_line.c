/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:49:54 by ilouacha          #+#    #+#             */
/*   Updated: 2023/05/23 09:33:34 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_found(t_list *stash)
{
	t_list	*current;
	int		i;

	if (stash == NULL)
		return (0);
	current = get_last_elt(&stash);
	while (current->content[i])
	{
		if (current->content[i] == "\n")
			return (1);
		i++;
	}
	return (0);
}

t_list	*get_last_elt(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
	{
		current = current->next;
	}
	return (current);
}

void	read_stash(int fd, t_list **stash)
{
	char	*buf;
	int		read_c;

	while (!found_new_line(*stash) && read_c != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		read_c = (int) read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && read_c == 0) || (read_c == -1))
		{
			free(buf);
			return ;
		}
		buf[read_c] = '\0';
		add_to_stash(*stash, buf, read_c);
		free(buf);
	}
}

void	add_to_stash(t_list **stash, char *buf, int *read_char)
{
	t_list	*current;
	t_list	*new_elt;

	new_elt = malloc(sizeof(t_list));
	if (new_elt == NULL)
		return ;
	new_elt->next = NULL;
	new_elt->content = malloc(sizeof(char) * (*read_char + 1));
	if (new_elt->content == NULL)
		return ;
	if (*stash == NULL)
	{
		*stash = new_elt;
		return ;
	}
	current = get_last_elt(*stash);
	current->next = new_elt;
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*stash;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nbr_read = 1;
	read_stash(fd, &stash);
	if (stash == NULL)
		return ;
	extract_line(&stash, &line);
	clean_stash(&stash);
	return (line);
}

/*char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*stash;
	int				nbr_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	nbr_read = 1;
	// 1. read and stash
	read_stash(fd, &stash, &nbr_read);
	// 2. extract from stash to line
	line = extract_line(&stash, );
	// 3. clean up stash
	while (read(fd, buf, BUFFER_SIZE) != 0)
	{
		if (!ft_strchr(buf, 10))
		{
			stash = ft_strjoin(stash, buf);
			count += BUFFER_SIZE;
		}
		else
		{
			count += BUFFER_SIZE - ft_strlen(ft_strchr(buf, 10)) + 1;
			line = (char *) ft_calloc(count, sizeof(char));
			i = 0;
			while (i < count)
			{
				line[i] = stash[i++];

			}

			while (buf[i - count] != '\n')
				line[i] = buf[i - count];
			return (line, ft_bzero(line));
			stash = ft_strchr(buf, 10);
		}
	}

}*/

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	return (1);
}
