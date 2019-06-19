/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:13:00 by apalaz            #+#    #+#             */
/*   Updated: 2019/02/20 16:52:09 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"

typedef struct		s_tetri
{
	char			tab[4][4];
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_coord
{
	int				tab_x[4];
	int				tab_y[4];
	char			letter;
	struct s_coord	*next;
}					t_coord;

int					ft_valid(char *file);
char				**ft_create_board(int size);
void				ft_print_board(char **board, int size);
int					ft_valid_tetri(t_tetri **head, t_coord **head_coord);
int					ft_check_file(int fd, t_tetri **head);
void				ft_free_list(t_tetri **lst);
int					ft_resolved_tetri(int nb_tetris, t_coord *head_coord);

#endif
