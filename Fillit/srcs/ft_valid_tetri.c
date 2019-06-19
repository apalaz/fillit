/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:21:07 by apalaz            #+#    #+#             */
/*   Updated: 2019/02/15 18:27:51 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_neighbour(int i, int j, int *neighbour, t_tetri *current)
{
	if (i > 0 && current->tab[i - 1][j] != '.')
		(*neighbour)++;
	if (i < 3 && current->tab[i + 1][j] != '.')
		(*neighbour)++;
	if (j > 0 && current->tab[i][j - 1] != '.')
		(*neighbour)++;
	if (j < 3 && current->tab[i][j + 1] != '.')
		(*neighbour)++;
}

static int		ft_valid_shape(t_tetri *current)
{
	int			i;
	int			j;
	int			neighbour;

	neighbour = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (current->tab[i][j] != '.')
			{
				ft_neighbour(i, j, &neighbour, current);
			}
			j++;
		}
		i++;
	}
	if (neighbour == 6 || neighbour == 8)
		return (1);
	return (0);
}

static void		ft_modif_coord(t_coord **current_coord)
{
	int			min_x;
	int			min_y;
	int			i;

	min_x = (*current_coord)->tab_x[0];
	min_y = (*current_coord)->tab_y[0];
	i = 1;
	while (i < 4)
	{
		if ((*current_coord)->tab_x[i] < min_x)
			min_x = (*current_coord)->tab_x[i];
		if ((*current_coord)->tab_y[i] < min_y)
			min_y = (*current_coord)->tab_y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*current_coord)->tab_x[i] = (*current_coord)->tab_x[i] - min_x;
		(*current_coord)->tab_y[i] = (*current_coord)->tab_y[i] - min_y;
		i++;
	}
}

static int		ft_count_char(t_tetri *current, t_coord **current_coord)
{
	int			i;
	int			j;
	int			count;
	static char	letter = 'A';

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (current->tab[i][j] != '.')
			{
				(*current_coord)->tab_x[count] = i;
				(*current_coord)->tab_y[count] = j;
				count++;
			}
		}
	}
	(*current_coord)->letter = letter;
	letter++;
	if (count == 4)
		return (1);
	return (0);
}

int				ft_valid_tetri(t_tetri **head, t_coord **head_coord)
{
	t_tetri		*current;
	t_coord		*current_coord;
	static int	nb_tetris = 0;

	current = *head;
	current_coord = *head_coord;
	while (current)
	{
		if (!(ft_count_char(current, &current_coord)))
			return (0);
		ft_modif_coord(&current_coord);
		if (!(ft_valid_shape(current)))
			return (0);
		if (current->next)
		{
			if (!(current_coord->next =
						(t_coord*)malloc(sizeof(*current_coord))))
				return (0);
			current_coord = current_coord->next;
			current_coord->next = NULL;
		}
		current = current->next;
		nb_tetris++;
	}
	return (nb_tetris);
}
