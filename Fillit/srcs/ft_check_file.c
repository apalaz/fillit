/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:04:50 by apalaz            #+#    #+#             */
/*   Updated: 2019/03/14 17:12:39 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_fill_tetri(int i, char *line, t_tetri **current)
{
	int		j;

	if (i < 4)
	{
		j = 0;
		while (line[j])
		{
			(*current)->tab[i][j] = line[j];
			j++;
		}
		i++;
	}
}

static int	ft_valid_line(int i, char *line)
{
	int		j;

	j = 0;
	if (i < 4)
	{
		if ((int)ft_strlen(line) != 4)
			return (0);
		while (line[j])
		{
			if (line[j] != '#' && line[j] != '.')
				return (0);
			j++;
		}
	}
	else if (i == 4)
	{
		if (line[j])
			return (0);
	}
	return (1);
}

static int	ft_malloc_currentnext(t_tetri **current, int *i)
{
	if (!((*current)->next = (t_tetri*)malloc(sizeof(**current))))
		return (0);
	(*current) = (*current)->next;
	(*current)->next = NULL;
	*i = 0;
	return (1);
}

int			ft_check_file(int fd, t_tetri **head)
{
	int		ret;
	int		i;
	char	*line;
	t_tetri	*current;

	i = 0;
	current = *head;
	while ((ret = get_next_line(fd, &line)))
	{
		if (!(ft_valid_line(i, line)))
			return (0);
		ft_fill_tetri(i, line, &current);
		i++;
		if (i == 4)
		{
			ret = get_next_line(fd, &line);
			if (ret > 0)
			{
				if (!(ft_valid_line(i, line)) ||
						(!(ft_malloc_currentnext(&current, &i))))
					return (0);
			}
		}
	}
	return (1);
}

void		ft_free_list(t_tetri **lst)
{
	while (*lst)
	{
		free(*lst);
		*lst = (*lst)->next;
	}
}
