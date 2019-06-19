/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:04:12 by apalaz            #+#    #+#             */
/*   Updated: 2019/02/15 18:27:23 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_valid(av[1]))
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
