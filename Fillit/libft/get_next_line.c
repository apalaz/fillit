/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:37:42 by apalaz            #+#    #+#             */
/*   Updated: 2019/02/20 16:42:44 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_check_error(int fd, char **line)
{
	if (fd < 0 || fd >= OPEN_MAX || !line)
		return (1);
	return (0);
}

int					ft_check_mem_buff(char **line, char *mem_buff)
{
	size_t			i;
	char			*temp;

	i = 0;
	while (mem_buff[i] && mem_buff[i] != '\n')
		i++;
	if (mem_buff[i] == '\n')
	{
		*line = ft_strsub(mem_buff, 0, i);
		i++;
		if (i < ft_strlen(mem_buff))
		{
			temp = ft_strnew(ft_strlen(&(mem_buff[i])));
			ft_strcpy(temp, &(mem_buff[i]));
			ft_bzero(mem_buff, BUFF_SIZE);
			ft_strcpy(mem_buff, temp);
			free(temp);
		}
		else
			ft_bzero(mem_buff, BUFF_SIZE);
		return (1);
	}
	*line = ft_strsub(mem_buff, 0, i);
	ft_bzero(mem_buff, BUFF_SIZE);
	return (0);
}

int					check_buff(char *buff, char **line, char *mem_buff)
{
	int				i;
	char			*temp;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
	{
		temp = ft_strsub(buff, 0, i);
		*line = ft_strjoin(*line, temp);
		free(temp);
		buff += i + 1;
		ft_strcpy(mem_buff, buff);
		return (1);
	}
	*line = ft_strjoin(*line, buff);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static char		mem_buff[OPEN_MAX][BUFF_SIZE];

	if (ft_check_error(fd, line))
		return (-1);
	if (ft_check_mem_buff(line, mem_buff[fd]))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (check_buff(buff, line, mem_buff[fd]))
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && **line)
		return (1);
	return (0);
}
