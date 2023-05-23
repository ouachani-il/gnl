/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:49:25 by ilouacha          #+#    #+#             */
/*   Updated: 2023/05/23 10:59:33 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# define SIZEMAXT 18446744073709551615UL

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		new_line_found(t_list *stash);
t_list	*get_last_elt(t_list *stash);
void	read_stash(int fd, t_list **stash);
void	add_to_stash(t_list **stash, char *buf, int *read_char);
void	extract_line(t_list *stash, char **line);
void	malloc_line(t_list *stash, char **line);
void	free_stash(t_list *stash);
void	clean_stash(t_list **stash);
size_t	ft_strlen(char *str);

#endif