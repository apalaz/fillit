/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-ches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:53:48 by gde-ches          #+#    #+#             */
/*   Updated: 2019/02/15 18:23:42 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_free_place(char **board, t_coord *head_coord, int *tab, int size)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i < 4)
	{
		x = head_coord->tab_x[i];
		y = head_coord->tab_y[i];
		if (x + tab[0] < size && board[x + tab[0]][y + tab[1]] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

static void	ft_put_tetri(char **board, t_coord *head_coord, int *tab)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i < 4)
	{
		x = head_coord->tab_x[i];
		y = head_coord->tab_y[i];
		board[x + tab[0]][y + tab[1]] = head_coord->letter;
		i++;
	}
}

static void	ft_del_tetri(char **board, t_coord *head_coord, int *tab)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i < 4)
	{
		x = head_coord->tab_x[i];
		y = head_coord->tab_y[i];
		board[x + tab[0]][y + tab[1]] = '.';
		i++;
	}
}

static int	ft_fill_board(char **board, int size, t_coord *head_coord)
{
	int tab[2];

	if (head_coord)
	{
		tab[0] = -1;
		while (++tab[0] < size)
		{
			tab[1] = -1;
			while (++tab[1] < size)
			{
				if (ft_free_place(board, head_coord, tab, size))
				{
					ft_put_tetri(board, head_coord, tab);
					if (ft_fill_board(board, size, head_coord->next))
						return (1);
					ft_del_tetri(board, head_coord, tab);
				}
			}
		}
		if (tab[0] == size && tab[1] == size)
			return (0);
	}
	return (1);
}

int			ft_resolved_tetri(int nb_tetris, t_coord *head_coord)
{
	char	**board;
	int		size;
	int		success;

	size = ft_sqrt(nb_tetris * 4);
	success = 0;
	while (!(success))
	{
		board = ft_create_board(size);
		success = ft_fill_board(board, size, head_coord);
		if (!(success))
		{
			free(board);
			size++;
		}
		else
			ft_print_board(board, size);
	}
	return (1);
}
