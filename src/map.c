/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:23 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/20 16:05:51 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../libft/gnl.h"

void	read_from_path(int fd, t_map *m_ptr)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = NULL;
	m_ptr->map = malloc(sizeof(char) * 69420);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		m_ptr->map[i] = buffer;
		i++;
	}
	m_ptr->map[i] = NULL;
	free(buffer);
	buffer = NULL;
}

void	print_map(t_map *m_ptr)
{
	int	row;
	int	col;

	row = 0;
	while (m_ptr->map[row])
	{
		col = 0;
		while (m_ptr->map[row][col])
		{
			if (m_ptr->map[row][col] == WALL)
				ft_printf("1");
			if (m_ptr->map[row][col] == PATH)
				ft_printf("0");
			if (m_ptr->map[row][col] == PLAYER)
				ft_printf("P");
			if (m_ptr->map[row][col] == EXIT)
				ft_printf("E");
			if (m_ptr->map[row][col] == BITBERRY)
				ft_printf("C");
			col++;
		}
		ft_printf("\n");
		row++;
	}
}

void	locate_player(t_game *g_ptr, t_map *m_ptr)
{
	int	row;
	int	col;

	row = 0;
	while (m_ptr->map[row])
	{
		col = 0;
		while (m_ptr->map[row][col])
		{
			if (m_ptr->map[row][col] == PLAYER)
			{
				g_ptr->player.row = row;
				g_ptr->player.col = col;
				ft_printf("PLAYER LOCATED: player row: %d\n",
					g_ptr->player.row);
				return ;
			}
			col++;
		}
		row++;
	}
}

void	get_map_size(t_map *m_ptr)
{
	int	row;
	int	col;

	row = 0;
	while (m_ptr->map[row])
	{
		col = 0;
		while (m_ptr->map[row][col])
		{
			col++;
		}
		row++;
	}
	m_ptr->map_col = col - 1;
	m_ptr->map_row = row;
	ft_printf("map_col: %d\n", m_ptr->map_col);
	ft_printf("map_row: %d\n", m_ptr->map_row);
}
