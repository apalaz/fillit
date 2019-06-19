/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:21:23 by apalaz            #+#    #+#             */
/*   Updated: 2019/02/15 18:26:35 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_valid(char *file)
{
	int			fd;
	int			nb_tetris;
	t_tetri		*head;
	t_coord		*head_coord;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!(head = (t_tetri*)malloc(sizeof(*head))))
		return (0);
	head->next = NULL;
	if (!(head_coord = (t_coord*)malloc(sizeof(*head_coord))))
		return (0);
	head_coord->next = NULL;
	if (!(ft_check_file(fd, &head)))
		return (0);
	nb_tetris = ft_valid_tetri(&head, &head_coord);
	if (nb_tetris > 26 || nb_tetris == 0)
		return (0);
	ft_free_list(&head);
	ft_resolved_tetri(nb_tetris, head_coord);
	return (1);
}
